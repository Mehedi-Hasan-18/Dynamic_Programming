class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sumOfNums = 0;
        int n = nums.size();
        for (int x : nums)
            sumOfNums += x;
        int sumOfSubset1 = (target + sumOfNums) / 2;
        
        if (abs(target) > sumOfNums || (target + sumOfNums) % 2 != 0) {
            return 0;
        } else {
            int dp[22][1005];
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= sumOfSubset1; j++) {
                    if (i == 0)
                        dp[i][j] = 0;
                    if (j == 0)
                        dp[i][j] = 1;
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= sumOfSubset1; j++) {
                    if (nums[i - 1] <= j) {
                        dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                    } else
                        dp[i][j] = dp[i - 1][j];
                }
            }

            return dp[n][sumOfSubset1];
        }
    }
};