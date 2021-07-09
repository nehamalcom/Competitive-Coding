class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> s_stack, t_stack;
        string s_final, t_final;

        for(int i=0; i<s.length(); i++) {
            if(s[i]=='#' && !(s_stack.empty())) {
                s_stack.pop();
            }
            else if(s[i]!='#'){
                s_stack.push(s[i]);
            }
        }
        for(int i=0; i<t.length(); i++) {
            if(t[i]=='#' && !(t_stack.empty())) {
                t_stack.pop();
            }
            else if(t[i]!='#')
                t_stack.push(t[i]);
        }


        while(!t_stack.empty()){
            t_final += t_stack.top();
            t_stack.pop();
        }
        while(!s_stack.empty()){
            s_final += s_stack.top();
            s_stack.pop();
        }

        cout<<s_final<<endl;
        cout<<t_final<<endl;

        if(s_final == t_final)
            return true;
        return false;

    }
};
