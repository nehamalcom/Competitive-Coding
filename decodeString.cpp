#include <stack>
#include <cstring>
class Solution {
public:
    string decodeString(string s) {
        stack<char> ans;
        string temp; //to store the strings to be reversed or multiplied
        char ch;
        char k;
        for (int i=0; i<s.length(); i++) {
            ch = s[i];
            ans.push(ch);
            if(ch == ']') {
                ans.pop();
                temp = "";
                while(true) {
                    k = ans.top();
                    ans.pop();
                    if(k!='[')
                        temp = temp + k;
                    else
                        break;
                }
                k = ans.top();
                int m = 0;
                int pos = 1;
                while(!ans.empty() && isdigit(ans.top())){
                    m = m + (ans.top()-'0')*pos;
                    ans.pop();
                    pos *= 10;
                }
                string tmp = "";
                while(m){
                    tmp += temp;
                    m--;
                }
                for(int r=tmp.length()-1; r>=0; r--) {
                    ans.push(tmp[r]);
                }
            }
        }
       temp = "";
        while(!ans.empty()){
            temp = temp + ans.top();
            ans.pop();
        }
        string final_ans = "";
        for(int r=temp.length()-1; r>=0; r--) {
                    final_ans += temp[r];
                }
        return final_ans;
    }
};
