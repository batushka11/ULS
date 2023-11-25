#include "../inc/libmx.h"

int mx_strlen(const char* s) {
	int length = 0;
	while(1) {
		if(s[length] != '\0') length++;
		else return length;
	}
}


