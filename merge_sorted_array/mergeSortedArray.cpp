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

  void printArray(vector<int> nums) {
    for (i = 0; i < nums.size(); i++) {
      cout << nums[i] << "\t";
    }
    cout << endl;
  }
};

int main() {
  Solution S1, S2, S3;

  vector<int> S1nums1, S1nums2, S2nums1, S2nums2, S3nums1, S3nums2;
  int S1m, S1n, S2m, S2n, S3m, S3n;

  S1nums1 = {1, 2, 3, 0, 0, 0};
  S1m = 3;
  S1nums2 = {2, 5, 6};
  S1n = 3;

  S2nums1 = {1};
  S2m = 1;
  S2nums2 = {};
  S2n = 0;

  S3nums1 = {0};
  S3m = 0;
  S3nums2 = {1};
  S3n = 1;

  S1.merge(S1nums1, S1m, S1nums2, S1n);
  S2.merge(S2nums1, S2m, S2nums2, S2n);
  S3.merge(S3nums1, S3m, S3nums2, S3n);

  S1.printArray(S1nums1);
  S2.printArray(S2nums1);
  S3.printArray(S3nums1);
}