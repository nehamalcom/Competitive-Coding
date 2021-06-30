class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
            unordered_map <string, int> e;
    string k;
    for (int i=0; i<emails.size(); i++) {
        int s=0;
        int at_flag=0;
        k = "";
        while (emails[i][s]!='@' && s<emails[i].length()) {
            if(emails[i][s]=='.')
                ;
            else if (emails[i][s]=='+')
                break;
            else
                k += emails[i][s];
            s++;
        }
        while(emails[i][s]!='@')
            s++;
        while(s<emails[i].length()){
            k += emails[i][s];
            s++;
        }
        cout<<k<<endl;
        e[k]++;
    }
    return e.size();
    }
};
