#include <unistd.h>

void ft_is_negative(int n);

int main(void) {
	ft_is_negative(0);
	return(0);
}

void ft_is_negative(int n) {
	char c  = (n < 0) ? 'N' : 'P';
	write(1, &c, 1);
}
