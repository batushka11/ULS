#include "../inc/libmx.h"

char **mx_strsplit(char const *s, char c) {
    	int i = 0;
    	int start = 0;
		int size = mx_count_words(s, c);
    	char **result = (char**)mx_strnew((size + 1) * sizeof(char*));
    	
    	for (int j = 0; j < size; j++) {
        	int length = 0;
        	start = i;
        	while (s[i] != c && s[i] != '\0') {
            	length++;
            	i++;
        	}

        	result[j] = mx_strndup(&s[start], length);
        	while (s[i] == c) {
           		i++;
        	}
    	}
    	result[size] = NULL;
    	
    	return result;
}




