#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int size;
    int k = 0;
public:
    int removeElement(vector<int>& nums, int val) {
        size = nums.size();

        for (int i = size -1; i >=0; i--) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
            }
            else {
                k++;
            }
        }

        return k;
    }
};