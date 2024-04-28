#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int temp;
  int k;
  int size;

public:
  int removeDuplicates(vector<int> &nums) {
    size = nums.size();
    temp = nums[size - 1];

    k = nums.empty() ? 0 : 1;

    for (int i = size - 2; i >= 0; i--) {
      if (nums[i] == temp) {
        nums.erase(nums.begin() + i);
      } else {
        k++;
        temp = nums[i];
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
  Solution S;

  vector<int> input1 = {1, 1, 2};
  vector<int> input2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int k1, k2;

  k1 = S.removeDuplicates(input1);
  k2 = S.removeDuplicates(input2);

  S.printArray(input1, k1);
  S.printArray(input2, k2);

  return 0;
}