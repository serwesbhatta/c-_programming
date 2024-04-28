#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int temp;
    int k;
    int size;
public:
    int removeDuplicates(vector<int>& nums) {
        size = nums.size();
        temp = nums[size - 1];

        k = nums.empty() ? 0 : 1;

        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] == temp) {
                nums.erase(nums.begin() + i);
            }
            else {
                k++;
                temp = nums[i];
            }
        }

        return k;
    }
};