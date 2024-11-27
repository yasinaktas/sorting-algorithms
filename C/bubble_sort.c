#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void bubble_sort(int *array, int size){
	int i, change = 1;
	while(change){
		change = 0;
		for(i = 0; i < size - 1; i++){
			if(array[i] > array[i + 1]){
				swap(array, i, i + 1);
				change = 1;
			}
		}
	}
}

int main(){
	int size = 20;
	int *array = createRandomArray(size);
	printArray(array,size);
	bubble_sort(array,size);
	printArray(array,size);
	printf("Is array sorted: %d\n",isArraySorted(array,size));
}
