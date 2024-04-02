#include <iostream>

using namespace std;

void inputElements(int array[], int size) {
  cout << "Enter " << size << " elements : " << endl;

  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }
}

int findMaxValue(int array[], int size) {
  int max = array[0];

  for (int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  return max;
}

// A is the input array, B is the output array and C is a temporary working
// array
void countingSort(int A[], int B[], int k, int size) {
  int C[k + 1];

  for (int i = 0; i <= k; i++) {
    C[i] = 0;
  }

  for (int j = 0; j < size; j++) {
    C[A[j]] = C[A[j]] + 1;
  }

  for (int i = 1; i <= k; i++) {
    C[i] = C[i] + C[i - 1];
  }

  for (int j = size - 1; j >= 0; j--) {
    B[C[A[j]] - 1] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
}

void printResult(int array[], int size) {
  cout << "The sorted elements are : " << endl;
  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
}

int main() {
  int size, maxValue;

  cout << "Enter the number of elements you want to sort: ";
  cin >> size;
  cout << endl;

  int inputArray[size], outputArray[size];

  inputElements(inputArray, size);

  maxValue = findMaxValue(inputArray, size);

  countingSort(inputArray, outputArray, maxValue, size);

  printResult(outputArray, size);

  return 0;
}