class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        i = 0;
        j = i+1;
        if(nums.size()==0)
            return 0;
        while (i<nums.size() && j<nums.size()) {
            if(nums[i]==nums[j]){
                j++;
            }
            else {
                nums[i+1] = nums[j];
                i++;
                j++;
            }
        }
        return i+1;
    }
};
