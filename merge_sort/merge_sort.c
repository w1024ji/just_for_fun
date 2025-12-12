#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

/**
* In the merge(), the temporary arry L and R's size changes regarding to mid value.
* If I want to use a array which size if defined within the runtime,
* better to use heap not stack(fixed size).
*
* <Merge Sort's Complexity>
* 1. divide: divide until one element is left. -> O(logn)
* 2. merge: maximum comparing is n1 + n2 - 1, proportional to size N -> O(n)
* => T(n) = O(logn) * O(n) = O(nlogn)
*
* Best thing about merge sort is the best, average and worst time complexity is O(nlogn)
*
* However, the downside is the this sorting requires additional memory space.
* 1. Auxiliary(Temporary) Array: O(n)
* 2. Stack space for recursion: O(logn)
* => S(n) = O(n) + O(logn) = O(n)
**/

void merge(int arr[], int left, int mid, int right);

void merge_sort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		// this will sort the left side
		merge_sort(arr, left, mid);
		// and this will sort the right side
		merge_sort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

/** 
* this function "merge" two sub arrays into one!
* 1. arr[left] ~ arr[mid]
* 2. arr[mid+1] ~ arr[right]
**/ 
void merge(int arr[], int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;	// the size of left subarray
	int n2 = right - mid;		// the size of right subarray

	// int L[n1], R[n2]; <- got error here.. :(
	// this is a solution!
	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));

	// be aware to check if it fails! (Memory Allocation Failure)
	if (L == NULL || R == NULL) {
		if (L) free(L);		
		if (R) free(R);
		return;
	}

	for (i = 0; i < n1; i++) L[i] = arr[left + i];
	for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

	i = 0; j = 0; k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) arr[k] = L[i++];
		else arr[k] = R[j++];
		k++;
	}

	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];

	// pls free the memory!
	free(L);
	free(R);
}

void print_array(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	int arr[SIZE] = { 8, 3, 1, 6, 2, 5 };

	printf("before merge sort: ");
	print_array(arr, SIZE); 

	merge_sort(arr, 0, SIZE - 1);

	printf("after merge sort: ");
	print_array(arr, SIZE);

	return 0;
}
