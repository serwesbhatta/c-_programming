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

  void printResult(vector<int> &nums, int target, int index) {
    if (targetFound == true) {
      cout << "The target " << target << " is found in given {";
      for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) {
          cout << ", ";
        }
      }
      cout << "} in the index " << index << "." << endl;
    } else {
      cout << "The target " << target << " could not be found in given {";
      for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) {
          cout << ", ";
        }
      }
      cout << "} so if the target was to insert in an ascending array it would "
              "be at index "
           << index << "." << endl;
    }
  }
};

int main() {
  Solution S1, S2, S3, S4, S5, S6;

  vector<int> input1234 = {1, 3, 5, 6};
  vector<int> input5 = {1, 3};
  vector<int> input6 = {1, 3, 5};

  int t1, t2, t3, t4, t5, t6;
  int index;
  t1 = 5;
  t2 = 2;
  t3 = 7;
  t4 = 0;
  t5 = 2;
  t6 = 4;

  index = S1.searchInsert(input1234, t1);
  S1.printResult(input1234, t1, index);

  index = S2.searchInsert(input1234, t2);
  S2.printResult(input1234, t2, index);

  index = S3.searchInsert(input1234, t3);
  S3.printResult(input1234, t3, index);

  index = S4.searchInsert(input1234, t4);
  S4.printResult(input1234, t4, index);

  index = S5.searchInsert(input5, t5);
  S5.printResult(input5, t5, index);

  index = S6.searchInsert(input6, t6);
  S6.printResult(input6, t6, index);
}