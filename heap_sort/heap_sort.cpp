#include <iostream>
#include <vector>
#include <algorithm>

void heapify(std::vector<int>& arr, int n, int i) {
	int biggest = i;		// parent
	int left = 2 * i + 1;	// left child
	int right = 2 * i + 2;	// right child

	// if left child is bigger than parent
	if (left <n && arr[left] > arr[biggest])
		biggest = left;
	// if right child is bigger than largest(parent or left)
	if (right < n && arr[right] > arr[biggest])
		biggest = right;

	// if parent is not the biggest, swap them 
	if (biggest != i) {
		std::swap(arr[i], arr[biggest]);
		heapify(arr, n, biggest);
	}
}

void heap_sort(std::vector<int>& arr) {
	int n = arr.size();

	// heapify from end to top
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {
	std::vector<int> data = { 12, 11, 13, 5, 7, 6 };
	heap_sort(data);

	for (int x : data) std::cout << x << " ";
	return 0;
}