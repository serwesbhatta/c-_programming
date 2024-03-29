#include <iostream>

using namespace std;

void inputElements(int array[], int size) {
  cout << "Enter " << size << " elements:" << endl;

  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
}

void insertionSort(int array[], int n) {
  int j, temp;

  for (int i = 1; i < n; i++) {
    temp = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > temp) {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = temp;
  }
}

void printResult(int array[], int size) {
  cout << "The elements after sorting are as follow: " << endl;

  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
}

int main() {
  int size;

  cout << "Enter the number of elements you want to sort: ";
  cin >> size;
  cout << endl;

  int array[size];

  inputElements(array, size);

  insertionSort(array, size);

  printResult(array, size);
}