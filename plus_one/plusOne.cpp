/*
We are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most
significant to least significant in left-to-right order. The large integer does
not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/

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

int main() {
  vector<vector<int>> digits = {
      {1, 2, 3}, {4, 3, 2, 1}, {9}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 5,
                                     9, 3, 5, 1, 6, 8, 4, 0, 1, 2}};

  vector<vector<int>> results(digits.size());

  for (int i = 0; i < digits.size(); i++) {
    Solution S;
    results[i] = S.plusOne(digits[i]);
  }

  for (int i = 0; i < results.size(); i++) {
    for (int j = 0; j < results[i].size(); j++) {
      cout << results[i][j] << " ";
    }
    cout << endl;
  }
}