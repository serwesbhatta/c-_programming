#include <iostream>

using namespace std;

void inputElements(int array[], int size) {
  cout << "Enter " << size << " elements :" << endl;

  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
}

int partition(int array[], int b, int e) {
  int p = b;

  while (b < e) {
    while (b < e && array[b] <= array[e])
      e--;

    if (array[b] > array[e]) {
      swap(array[b], array[e]);
      p = e;
      b++;
    }

    while (b < e && array[b] <= array[e])
      b++;

    if (array[b] > array[e]) {
      swap(array[b], array[e]);
      p = b;
      e--;
    }
  }

  return p;
}

void quickSort(int array[], int p, int r) {
  int q;

  if (p < r) {
    q = partition(array, p, r);
    quickSort(array, p, q - 1);
    quickSort(array, q + 1, r);
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

  cout << "Enter the number of elements that you want to sort : ";
  cin >> size;
  cout << endl;

  int array[size];

  inputElements(array, size);

  quickSort(array, 0, size - 1);

  printResult(array, size);

  return 0;
}