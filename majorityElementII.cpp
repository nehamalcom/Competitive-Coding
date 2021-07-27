class Solution {
public:
    bool getFreq(vector<int>&nums, int a ) {
        int n = nums.size();
        int freq = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]==a)
                freq++;
        }
        if(freq>n/3)
            return true;
        else
            return false;
    }
    vector<int> findCandidate(vector<int>& nums) {
        int cand1 = INT_MAX, count1 = 0;
        int cand2 = INT_MAX, count2 = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i]==cand1)
                count1++;
            else if(nums[i]==cand2)
                count2++;
            else if(count1==0) {
                cand1 = nums[i];
                count1 = 1;
            }
            else if(count2==0) {
                cand2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        if(cand1!=INT_MAX && getFreq(nums,cand1))
            ans.push_back(cand1);
        if(cand2!=INT_MAX && getFreq(nums,cand2))
            ans.push_back(cand2);
        return ans;
    }
    vector<int> majorityElement(vector<int>& nums) {
        return findCandidate(nums);

    }
};
