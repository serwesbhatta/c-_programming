/*
Given a non-negative integer x, return the square root of x rounded down to the
nearest integer. The returned integer should be non-negative as well.

Must not use any built-in exponent function or operator.
*/

#include <iostream>

using namespace std;

class Solution {
private:
  long left, right, mid, square;

public:
  int mySqrt(int x) {
    if (x == 0 || x == 1) {
      return x;
    }

    left = 1;
    right = x;

    while (left < right) {
      mid = left + (right - left) / 2;
      square = mid * mid;

      if (square == x) {
        return mid;
      }

      else if (square < x) {
        left = mid + 1;
      }

      else {
        right = mid;
      }
    }

    return left - 1;
  }
};

int main() {
  Solution S1, S2;

  int input1 = 4, input2 = 8;

  int root1, root2;

  root1 = S1.mySqrt(input1);
  root2 = S2.mySqrt(input2);

  cout << "The square root of " << input1 << " is " << root1 << "." << endl;
  cout << "The square root of " << input2 << " is " << root2 << "." << endl;
}