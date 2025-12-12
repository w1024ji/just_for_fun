#include <iostream>
#include <vector>
#include <algorithm> 

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0; int j = 0; int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

}
/** 
* recursive
void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
**/

// iterative
void iterative_merge_sort(std::vector<int>& arr) {
    int n = arr.size();

    // size: (1 -> 2 -> 4 -> 8 ...)
    for (int size = 1; size < n; size *= 2) {

        // left: (0, 2*size, 4*size, ...)
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, n - 1);

            merge(arr, left, mid, right);
        }
    }
}

void print_vector(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = { 8, 3, 1, 6, 2, 5 };

    std::cout << "before merge sort cpp: ";
    print_vector(data);

    // merge_sort(data, 0, data.size() - 1);
    iterative_merge_sort(data);

    std::cout << "after merge sort cpp: ";
    print_vector(data);

    return 0;
}
