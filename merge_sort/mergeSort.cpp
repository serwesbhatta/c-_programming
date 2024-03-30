#include <iostream>

using namespace std;

void inputElements(int *array, int size) {
  cout << "Enter " << size << " elements : " << endl;

  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
}

void merge(int *left, int *right, int *array, int size) {
  int i = 0, j = 0, k = 0;

  while (i < size / 2 && j < size - size / 2) {
    if (left[i] < right[j]) {
      array[k++] = left[i++];
    } else {
      array[k++] = right[j++];
    }
  }

  while (i < size / 2) {
    array[k++] = left[i++];
  }

  while (j < size - size / 2) {
    array[k++] = right[j++];
  }

  delete[] left;
  delete[] right;
}

void mergeSort(int *array, int size) {
  int i, mid, *left, *right;

  if (size >= 2) {
    mid = size / 2;
    left = new int[mid];
    right = new int[size - mid];

    for (int i = 0; i < mid; i++)
      left[i] = array[i];

    for (int i = mid; i < size; i++)
      right[i - mid] = array[i];

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(left, right, array, size);
  }
}

void printResult(int *array, int size) {
  cout << "The elements are sorted in the following way : " << endl;

  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
}

int main() {
  int size;

  cout << "Enter the number of elemetns that you want to sort : ";
  cin >> size;
  cout << endl;

  int *array = new int[size];

  inputElements(array, size);

  mergeSort(array, size);

  printResult(array, size);

  delete[] array;

  return 0;
}