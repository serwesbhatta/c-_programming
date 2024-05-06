/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 45
*/

#include <iostream>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }
};

int main() {
  Solution S1, S2, S3;

  int n[3];
  n[0] = 2;
  n[1] = 3;
  n[2] = 45;
  int steps[3];

  steps[0] = S1.climbStairs(n[0]);
  steps[1] = S2.climbStairs(n[1]);
  steps[2] = S3.climbStairs(n[2]);

  for (int i = 0; i < 3; i++) {
    cout << "The number of ways to climb " << n[i] << " steps is " << steps[i] << "." << endl;
  }
}