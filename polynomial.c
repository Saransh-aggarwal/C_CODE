#include <stdio.h>
#include <stdlib.h>


typedef struct Polynomial Polynomial;
struct Polynomial {
    int coef;
    int exp;
    struct Polynomial *next;
};

static inline Polynomial* init_polynomial() {
    Polynomial *new_poly = (Polynomial*)malloc(sizeof(Polynomial));
    if (new_poly != NULL)
        new_poly->next = NULL;
    return new_poly;
}

static inline void set_polynomial(Polynomial *poly, int coef, int exp) {
    poly->coef = coef;
    poly->exp = exp;
}

int insert_polynomial(Polynomial **poly, int coef, int exp) {
    Polynomial *new_poly = init_polynomial();
    set_polynomial(new_poly, coef, exp);
    if (*poly == NULL) {
        *poly = new_poly;
    } else {
        Polynomial *tmp = *poly;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_poly;
    }
    return 0;
}

Polynomial* get_polynomial_sum(Polynomial *poly1, Polynomial *poly2) {
    Polynomial *sum = NULL;
    /* working under the assumption that the terms
     * of the polynomial have been sorted in descending order */
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            int coef = poly1->coef + poly2->coef;
            int exp = poly1->exp;
            insert_polynomial(&sum, coef, exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insert_polynomial(&sum, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insert_polynomial(&sum, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }
    /* insert any remaning terms from each polynomial */
    while (poly1 != NULL) {
        insert_polynomial(&sum, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insert_polynomial(&sum, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }
    return sum;
}

void print_polynomial(Polynomial *poly) {
    Polynomial *head = poly;
    for (; poly != NULL; poly = poly->next) {
        int coef = poly->coef, exp = poly->exp;
        /* print the term, only if the coefficient is not 0
         * aditionally, if the coefficient is unity, print only the power of x */
        if (coef) {
            if (coef != 1)
                printf("%d", coef);
            if (coef == 1 && exp == 0)
                putchar('1');
            /* print the exponent */
            if (exp != 0 && exp != 1) {
                printf("x^%d", exp);
            } else if (exp == 1) {
                putchar('x');
            }
        } else if (!coef && poly->next == NULL && poly ==  head) {
            /* print 0 if this is a zero polynomial */
            putchar('0');
        }
        /* a '+' has to be added if there exists another term,
         * the coefficient of the next term is not zero and if this term is not a zero at the beginning */
        if (poly->next != NULL && poly->next->coef) {
            printf(" + ");
        }
    }
    putchar('\n');
}


int main() {
    Polynomial *p1 = NULL;
    insert_polynomial(&p1, 5, 4);
    insert_polynomial(&p1, 3, 2);
    insert_polynomial(&p1, 1, 0);
    printf("First Polynomial is:\t");
    print_polynomial(p1);

    Polynomial *p2 = NULL;
    insert_polynomial(&p2, 3, 5);
    insert_polynomial(&p2, 4, 4);
    insert_polynomial(&p2, 2, 2);
    insert_polynomial(&p2, 0, 1);
    insert_polynomial(&p2, 3, 0);
    printf("Second Polynomial is:\t");
    print_polynomial(p2);

    Polynomial *sum = get_polynomial_sum(p1, p2);
    printf("Sum:\t\t\t");
    print_polynomial(sum);

    return 0;
}
