#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int findPivotIndex(int *array, int start, int end){
	int pivot = start;
	start++;
	while(start <= end){
		if(array[pivot] > array[start]){
			start++;
		}else if(array[pivot] <= array[end]){
			end--;
		}else{
			swap(array, start, end);
			start++;
			end--;
		}
	}
	swap(array, pivot, end);
	return end;
}

void quickSort(int *array, int start, int end){
	if(start < end){
		int pivotIndex = findPivotIndex(array, start, end);
		quickSort(array, start, pivotIndex - 1);
		quickSort(array, pivotIndex + 1, end);
	}
}

int main(){
	int size = 20;
	int *array = createRandomArray(size);
	//printArray(array,20);
	quickSort(array, 0, size - 1);
	//printArray(array, 20);
	printf("Is array sorted: %d\n", isArraySorted(array, size));
	free(array);
}
