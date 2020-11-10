#include <unistd.h>

void ft_print_comb(void);

int main(void) {
	ft_print_comb();
	return(0);
}

void ft_print_comb(void) {
    char comma = ',';
    char space = ' ';
    char a = '0';
    char b = a + 1;
    char c = b + 1;
    while (a <= '9') {
        while (b <= '9') {
            while (c <= '9') {
                if (c == '2') {
                    write(1, &a, 1);
                    write(1, &b, 1);
                    write(1, &c, 1);
                }
                else {
                    write(1, &comma, 1);
                    write(1, &space, 1);
                    write(1, &a, 1);
                    write(1, &b, 1);
                    write(1, &c, 1);
                }
                c++;
            }
            b++;
            c = b + 1;
        }
        a++;
        b = a + 1;
        c = b + 1;
    }
}
