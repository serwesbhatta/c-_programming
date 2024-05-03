#include <iostream>

using namespace std;

class Solution {
private:
  int sum, i, j, carry;
  string result;

public:
  Solution() {
    sum = 0;
    carry = 0;
    result = "";
  }

  string addBinary(string a, string b) {
    i = a.length() - 1;
    j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
      sum = carry;

      if (i >= 0) {
        sum += a[i--] - '0';
      }

      if (j >= 0) {
        sum += b[j--] - '0';
      }

      result = to_string(sum % 2) + result;
      carry = sum / 2;
    }

    return result;
  }
};