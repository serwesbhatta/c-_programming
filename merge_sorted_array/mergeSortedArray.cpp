#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int i, j, k;

public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    i = m - 1;
    j = n - 1;
    k = m + n - 1;

    nums1.resize(m + n);

    while (i >= 0 && j >= 0) {
      if (nums1[i] > nums2[j]) {
        nums1[k--] = nums1[i--];
      } else {
        nums1[k--] = nums2[j--];
      }
    }

    while (j >= 0) {
      nums1[k--] = nums2[j--];
    }
  }
};