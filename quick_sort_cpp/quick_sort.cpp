#include <iostream>
#include <algorithm>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; // C의 \n 대신 std::endl 사용
}

int main() {
    int data[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(data) / sizeof(data[0]);

    std::cout << "arrary before quicksort: ";
    printArray(data, n);

    quickSort(data, 0, n - 1);

    std::cout << "arrary after quicksort: ";
    printArray(data, n);

    return 0;
}

