class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 1); // since all elements individually are subsequences
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j]<nums[i]) {
                    // we can form a subsequence starting from here
                    dp[i] = dp[i]>(dp[j]+1)?dp[i]:dp[j]+1;
                }
            }
        }
        int max_length = INT_MIN;
        for(int i=0; i<dp.size(); i++)
            if(dp[i]>max_length)
                max_length = dp[i];
        return max_length;
    }
};
