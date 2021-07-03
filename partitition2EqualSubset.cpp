class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n, sum, i, j;
        n = nums.size();
        i = 0;
        sum = 0;
        // get the sum of all the elements
        while(i<n){
            sum += nums[i];
            i++;
        }

        // check if it is possible to have two subsets
        if(sum%2 != 0)
            return false;

        sum = sum/2;

        bool s[n+1][sum+1];

        // if sum is zero
        for (int i=0; i<=n; i++) {
            s[i][0] = true;
        }

        // if we are taking no elements
        for (int j=0; j<=sum; j++) {
            s[0][j] = false;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {
                // if there is no space to fit in the element
                if(j-nums[i-1]<0) {
                    s[i][j] = s[i-1][j];
                }
                else {
                    // if there is space choose to take it or not
                    s[i][j] = s[i-1][j] || s[i-1][j-nums[i-1]];
                }

            }
        }
        return s[n][sum];
    }
};
