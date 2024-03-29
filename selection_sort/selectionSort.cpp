#include <iostream>

using namespace std;

void inputElements(int array[], int size) {
  cout << "Enter " << size << " elements : " << endl;
  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
}

void selectionSort(int array[], int size) {
  int minIndex;

  for (int i = 0; i < size - 1; i++) {
    minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (array[minIndex] > array[j]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(array[minIndex], array[i]);
    }
  }
}

void swap(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void printResult(int array[], int size) {
  cout << "The sorted elements are as follows : " << endl;
  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
}

int main() {
  int size;

  cout << "Enter the number of elements to be sorted: ";
  cin >> size;
  cout << endl;

  int array[size];

  inputElements(array, size);

  selectionSort(array, size);

  printResult(array, size);

  return 0;
}