#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int size, left, right, mid, index;
  bool targetFound = false;

public:
  int searchInsert(vector<int> &nums, int target) {
    size = nums.size();

    if (size == 0) {
      return 0;
    }

    left = 0;
    right = size - 1;

    index = binarySearch(nums, left, right, target);

    if (targetFound == false) {
      if (target >= nums[index]) {
        return index + 1;
      }
    }

    return index;
  }

  int binarySearch(vector<int> &nums, int left, int right, int target) {
    mid = (left + right) / 2;

    if (nums[mid] == target) {
      targetFound = true;
      return mid;
    } else if (left >= right) {
      targetFound = false;
      return mid;
    } else if (target < nums[mid]) {
      return binarySearch(nums, left, mid - 1, target);
    } else {
      return binarySearch(nums, mid + 1, right, target);
    }
  }
};