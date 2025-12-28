def quicksort(A, low, high):
  def partition(low, high):
    pivot = A[high]
    left = low
    for right in range(low, high):
      if A[right] < pivot:
        A[left], A[right] = A[right], A[left]
        left += 1
    A[left], A[high] = A[high], A[left]
    return left

if low < high:
  pivot = partition(low, high)
  quicksort(A, low, pivot -1)
  quicksort(A, pivot + 1, high)

