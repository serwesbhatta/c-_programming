#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> result;
  int carry, sum, i;

public:
  vector<int> plusOne(vector<int> &digits) {
    result.resize(digits.size(), 0);
    carry = 1;

    for (i = digits.size() - 1; i >= 0; i--) {
      sum = digits[i] + carry;
      result[i] = sum % 10;
      carry = sum / 10;
    }

    if (carry == 1) {
      result.insert(result.begin(), carry);
    }

    return result;
  }
};