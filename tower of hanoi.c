#include <stdio.h>

void tower_of_hanoi(int n, char source_rod, char target_rod, char auxiliary_rod);

int main() {
    tower_of_hanoi(3, 'A', 'C', 'B');
    return 0;
}


void tower_of_hanoi(int n, char source_rod, char target_rod, char auxiliary_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source_rod, target_rod);
        return;
    }

    
    
    tower_of_hanoi(n - 1, source_rod, auxiliary_rod, target_rod);
    printf("Move disk %d from %c to %c\n", n, source_rod, target_rod);
    tower_of_hanoi(n - 1, auxiliary_rod, target_rod, source_rod);
}
