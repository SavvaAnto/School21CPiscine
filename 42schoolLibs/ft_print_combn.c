#include <stdio.h>

void ft_print_combn(int n);

int main(void) {
    ft_print_combn(3);
    return(0);
}

void ft_print_combn(int n) {
    int i, j, l, ctr;
    int comb[n];
    //creating intitial comb
    i = n - 1;
    while (i >= 0) {
        comb[i] = i;
        i--;
    }
    while (comb[0] <= 10 - n) {
        //comb output
        i = 0;
        while (i < n) {
            printf("%d", comb[i]);
            i++;
        }
        if (comb[0] == 10 - n) break;
        printf(", ");
        //inrementing the last digit
        comb[n - 1]++;
        //check that the digits aint overloaded
        j = n - 1;
        ctr = 0;
        while (j >= 0) {
            if (comb[j] <= 9 - ctr ) break;
            else {
                comb[j - 1]++;
                l = 0;
                while (l < ctr + 1) {
                    comb[j + l] = comb[j + l - 1] + 1;
                    l++;
                }
            }
            ctr++;
            j--;
        }
    }
    printf("\n");
}
