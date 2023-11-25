#include "../inc/libmx.h"

void mx_printlong(long long n){
    if (n == 0) {
		mx_printchar('0');
		return;
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

