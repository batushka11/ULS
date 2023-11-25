#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
	int count_swap = 0;
	int isSorted = 0;
	
	while(!isSorted) {
		isSorted = 1;
		for(int i = 0; i < size - 1; i++) {
			if(mx_strcmp(arr[i], arr[i + 1]) > 0) {
				isSorted = 0;
				count_swap++;
				
				char *buff = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buff;
			}
		}
	}
	
	return count_swap;
}


