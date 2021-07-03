#include <map>
class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> m;
        int currPos = 0, time = 0, nextPos;
        for(int i=0; i<keyboard.length(); i++) {
            m[keyboard[i]] = i;
        }
        for(int i=0; i<word.length(); i++) {
            int letter = word[i];
            cout<<currPos;
            nextPos = m[letter];
            time += (nextPos - currPos)>0? (nextPos - currPos):(currPos - nextPos);
            currPos = nextPos;
        }
        return time;
    }
};
