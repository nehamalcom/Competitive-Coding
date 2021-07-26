class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.push_back({1});

        int rowLen = 2;

        for(; rowLen<=numRows; rowLen++) {
            vector<int> v(rowLen);
            v[0] = 1;
            v[rowLen-1] = 1;
            for(int j=1; j<rowLen-1; j++) {
                v[j] = pascal.back()[j-1] + pascal.back()[j];
            }
            pascal.push_back(v);
        }

        return pascal;
    }
};
