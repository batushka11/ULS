#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
	int number_of_words = 0;
	int length = 0;
	
	for(int i = 0; str[i] != '\0'; i++) {
		length++;
	}
	int start = 0;
	int end = length - 1;
	
	for(int i = 0; i < length; i++) {
		if(str[i] != delimiter) {
			break;
		}
		start++;
	}
	for(int i = end; i >= 0; i--) {
		if(str[i] != delimiter) {
			break;
		}
		end--;
	}
	for(int i = start; i <= end; i++) {
		if(str[i] == delimiter && str[i + 1] == delimiter) {
			continue;
		}
		if(str[i] == delimiter) {
			number_of_words++;
		}
	}
	
	return number_of_words + 1;
}


