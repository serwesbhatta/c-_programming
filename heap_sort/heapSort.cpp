#include <iostream>

using namespace std;

void inputElements(int array[], int size) {
  cout << "Enter " << size << " elements : " << endl;

  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
}

void heapify(int array[], int size, int i) {
  int largest = i;
  int left = i * 2 + 1;
  int right = i * 2 + 2;

  if (left < size && array[left] > array[largest])
    largest = left;

  if (right < size && array[right] > array[largest])
    largest = right;

  if (largest != i) {
    swap(array[i], array[largest]);

    heapify(array, size, largest);
  }
}

void heapSort(int array[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }

  for (int i = size - 1; i > 0; i--) {
    swap(array[0], array[i]);
    heapify(array, i, 0);
  }
}

void printElements(int array[], int size) {
  cout << "The elements are sorted in the following way : " << endl;

  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
}

int main() {
  int size;

  cout << "Enter the number of elements you want to sort : ";
  cin >> size;
  cout << endl;

  int array[size];

  inputElements(array, size);

  heapSort(array, size);

  printElements(array, size);

  return 0;
}