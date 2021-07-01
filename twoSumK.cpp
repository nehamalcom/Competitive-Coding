class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum=-1;
        int hi, lo;
        lo = 0;
        hi = nums.size()-1;
        while(lo<hi) {
            if((nums[lo]+nums[hi])<k){
                if((nums[lo]+nums[hi])>sum)
                    sum= nums[lo]+nums[hi];
                lo++;
            }
            else{
                hi--;
            }
        }
        return sum;
    }
};
