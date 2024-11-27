#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void selection_sort(int *array, int size){
	int i, j, min;
	for(i = 0; i < size - 1; i++){
		min = i;
		for(j = i + 1; j < size; j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		swap(array, min, i);
	}
}

int main(){
	int size = 20;
	int *array = createRandomArray(size);
	printArray(array,size);
	selection_sort(array,size);
	printArray(array,size);
	printf("Is array sorted: %d\n", isArraySorted(array,size));
}
