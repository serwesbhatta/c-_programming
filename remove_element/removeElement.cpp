#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int size;
  int k = 0;

public:
  int removeElement(vector<int> &nums, int val) {
    size = nums.size();

    for (int i = size - 1; i >= 0; i--) {
      if (nums[i] == val) {
        nums.erase(nums.begin() + i);
      } else {
        k++;
      }
    }

    return k;
  }

  void printArray(vector<int> &nums, int size) {
    for (int i = 0; i < size; i++) {
      printf("%d\t", nums[i]);
    }
    printf("\n");
  }
};

int main() {
  Solution S1, S2;

  vector<int> input1 = {3, 2, 2, 3};
  vector<int> input2 = {0, 1, 2, 2, 3, 0, 4, 2};

  int val1 = 3;
  int val2 = 2;

  int k1, k2;

  k1 = S1.removeElement(input1, val1);
  k2 = S2.removeElement(input2, val2);

  S1.printArray(input1, k1);
  S2.printArray(input2, k2);
}