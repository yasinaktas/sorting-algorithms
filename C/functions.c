#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffleArray(int *array, int n){
	int i, j, temp;
	srand(time(NULL));
	for(i = n - 1; i > 0; i--){
		j = rand() % (i + 1);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

int *createSortedArray(int n){
	int i;
	int *array = (int *)malloc(n * sizeof(int));
	for(i = 0; i < n; i++){
		array[i] = i + 1;
	}
	return array;
}

int *createRandomArray(int n){
	int *array = createSortedArray(n);
	shuffleArray(array, n);
	return array;
}

int isArraySorted(int *array, int n){
	int i;
	for(i = 0; i < n - 1; i++){
		if(array[i] > array[i + 1]){
			return 0;
		}
	}
	return 1;
}

void swap(int *array, int a, int b){
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void printArray(int *array, int n){
	int i;
	printf("\n");
	for(i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
