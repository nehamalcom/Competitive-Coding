class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
            smallest = smallest<nums[i]?smallest:nums[i];
            largest = largest>nums[i]?largest:nums[i];
        }

        int count = 0;
        int maxCount = 0;
        for(auto i: m) {
            if(m.find(i.first-1)==m.end()) {
                int k = i.first;
                count = 1;
                while(m.find(++k)!=m.end())
                    count++;
            }
            maxCount = maxCount>count?maxCount:count;
        }

        return maxCount;
    }
};
