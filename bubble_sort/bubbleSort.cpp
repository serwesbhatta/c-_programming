#include <iostream>

using namespace std;

void bubbleSort(int array[], int size) {
  bool swapped = true;
  int j = 0;

  while (swapped) {
    swapped = false;
    j++;

    for (int i = 0; i < size - j; i++) {
      if (array[i] > array[i + 1]) {
        swap(array[i], array[i + 1]);
        swapped = true;
      }
    }
  }
}

void swap(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void inputElements(int array[], int size) {
  cout << "Enter " << size << " elements: " << endl;
  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
}

void printResult(int array[], int size) {
  cout << "The sorted elements are : " << endl;
  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
}

int main() {
  int size;

  cout << "Enter the size of array you want to sort: ";
  cin >> size;

  int array[size];

  inputElements(array, size);

  bubbleSort(array, size);

  printResult(array, size);

  return 0;
}
