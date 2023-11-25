#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {	
	if(arr == NULL) {
		return -1;
	}
 
    int i = left, j = right, count = 0;
    char *pivot = arr[(left + right) / 2];
    	
    while(i <= j) {
        while(mx_strlen(arr[i]) < mx_strlen(pivot)) {
            	i++;
        }
        while(mx_strlen(arr[j]) > mx_strlen(pivot)) {
            	j--;
        }
        if (i <= j) {
            if(mx_strlen(arr[i]) > mx_strlen(arr[j])) {
                char *tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                count++;
            }
            
            i++;
            if (j > 0) {
                j--;
            }
        }
    }
 
    if (i < right) {
        count += mx_quicksort(arr, i, right);
    }
    if (j > left) {
        count += mx_quicksort(arr, left, j);
    }

	return count;
}


