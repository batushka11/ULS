#include "../inc/libmx.h"

void mx_printint(int n) {
	if (n == 0) {
		mx_printchar('0');
		return;
	}
	else if (n == -2147483648) {
		write(1, "-2147483648", 11);
		return;
	}
	else if (n < 0) {
		mx_printchar('-');
		n *= -1;
	}
	int start = n;
	int number_of_digits = 0;
	while(start > 0) {
		start /= 10;
		number_of_digits++;
	}
	int number[number_of_digits];
	int counter = 0;
	while(n > 0) {
		number[counter] = n % 10;
		n /= 10;
		counter++;
	}
	for(int i = counter - 1; i >= 0; i--) {
		mx_printchar(number[i] + 48);
	}
}


