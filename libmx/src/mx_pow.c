#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
	double pow_number = n;
	if(pow == 0) {
		return 1;
	}
	for(unsigned int i = 1; i < pow; i++) {
		pow_number *= n;
	}
	return pow_number;
}


