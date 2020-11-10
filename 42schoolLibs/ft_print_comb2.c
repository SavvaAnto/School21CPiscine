#include <stdio.h>

void ft_print_comb2(void);

int main(void) {
    ft_print_comb2();
    return(0);
}

void ft_print_comb2(void) {
    int a = 0;
    int b = a + 1;
    while (a <= 99) {
        while (b <= 99) {
            if (a == 0 && b == 1) {
                printf("00 01");
            }
            else {
                if (a <= 9) {
                    printf(", 0%d", a);
                }
                else {
                    printf(", %d", a);
                }
                if (b <= 9) {
                    printf(" 0%d", b);
                }
                else {
                    printf(" %d", b);
                }
            }
            b++;
        }
        a++;
        b = a + 1;
    }
	printf("\n");
}
