#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void insertion_sort(int *array, int size){
	int i, j;
	for(i = 1; i < size; i++){
		for(j = i; j > 0; j--){
			if(array[j] < array[j - 1]){
				swap(array, j, j - 1);
			}
		}
	}
}

int main(){
	int size = 20;
	int *array = createRandomArray(size);
	printArray(array,size);
	insertion_sort(array,size);
	printArray(array,size);
	printf("Is array sorted: %d\n",isArraySorted(array,size));
}
