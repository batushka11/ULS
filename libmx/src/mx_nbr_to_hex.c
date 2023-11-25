#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	if(nbr == 0) {
        	char * hex_number = (char*)malloc(1);
        	hex_number[0] = '0';
        	return hex_number;
    	}
	
	unsigned long start = nbr;
	int number_of_digits = 0;
	
	while(start > 0) {
		start /= 16;
		number_of_digits++;
	}
	char *hex_number = (char*)malloc(number_of_digits);
	
	int counter = number_of_digits - 1;
	while(nbr > 0) {
		int buff = nbr % 16;
		switch(buff) {
			case 10:
				hex_number[counter] = 'a';
				break;
			case 11:
				hex_number[counter] = 'b';
				break;
			case 12:
				hex_number[counter] = 'c';
				break;
			case 13:
				hex_number[counter] = 'd';
				break;
			case 14:
				hex_number[counter] = 'e';
				break;
			case 15:
				hex_number[counter] = 'f';
				break;
			default:
				hex_number[counter] = buff + 48;
				break;
		}
		nbr /= 16;
		counter--;
	}
	return hex_number;
}


