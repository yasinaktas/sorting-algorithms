#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void merge(int *array, int start, int mid, int end){
	int i, j, k;
	int size1 = mid - start + 1;
	int size2 = end - (mid + 1 ) + 1;

	int *subArray1 = (int *)malloc(size1 * sizeof(int));
	int *subArray2 = (int *)malloc(size2 * sizeof(int));

	for(i = 0; i < size1; i++){
		subArray1[i] = array[start + i];
	}
	for(i = 0; i < size2; i++){
		subArray2[i] = array[mid + 1 + i];
	}
	i = 0;
	j = 0;
	k = start;
	while(i < size1 && j < size2){
		if(subArray1[i] < subArray2[j]){
			array[k] = subArray1[i];
			i++;
		}else{
			array[k] = subArray2[j];
			j++;
		}
		k++;
	}
	while(i < size1){
		array[k] = subArray1[i];
		i++;
		k++;
	}
	while(j < size2){
		array[k] = subArray2[j];
		j++;
		k++;
	}
}

void merge_sort(int *array, int start, int end){
	if(start < end){
		int mid = (end + start) / 2;
		merge_sort(array, start, mid);
		merge_sort(array, mid + 1, end);
		merge(array, start, mid, end);
	}
}

int main(){
	int size = 20;
	int *array = createRandomArray(size);
	printArray(array,size);
	merge_sort(array, 0, size - 1);
	printArray(array, size);
	printf("Is array sorted: %d\n",isArraySorted(array, size));
}

