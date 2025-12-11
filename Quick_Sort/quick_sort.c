#include <stdio.h>

/**
* Quick sort is based on Divide and Conquer. Which means 1. divide, 2. conquer and 3. combine.
* Pivot and Partitioning is key point of quick sort!
* 
* Average Time Complexity: O(nlogn)
* Worst Time Complexity: O(n^2) <- this happens when the pivot is the smallest or biggest.
* Space Complextiy: O(logn)
**/

// print array
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// for partition array - bigger than pivot or not? -
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			// swap arr[i] <-> arr[j]
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	
	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;

	return (i + 1);
}

// let's do recursion
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);

		quickSort(arr, low, pivot - 1); // the left side (small)
		quickSort(arr, pivot + 1, high); // the right side (big)
	}
}

int main() {
	int data[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(data) / sizeof(data[0]);

	printf("before quicksort: ");
	printArray(data, n); // [10 7 8 9 1 5] 

	quickSort(data, 0, n - 1);

	printf("after quicksort: ");
	printArray(data, n); // [1 5 7 8 9 10]

	return 0;
}