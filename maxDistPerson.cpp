class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> closestOnRight(seats.size());
        vector<int> closestOnLeft(seats.size());

        closestOnRight[seats.size()-1]=seats.size();
        closestOnLeft[0]=seats.size();

        for(int i=seats.size()-1; i>=0; i--) {
            if(seats[i]==1)
                closestOnRight[i] = 0;
            else if (i<seats.size()-1)
                closestOnRight[i] = closestOnRight[i+1]+1;
        }
        cout<<endl;
        for(int i=0; i<seats.size(); i++) {
            if(seats[i]==1)
                closestOnLeft[i] = 0;
            else if (i>0)
                closestOnLeft[i] = closestOnLeft[i-1]+1;
            cout<<closestOnLeft[i]<< " ";
        }

        int ans = INT_MIN;
        for(int i=0; i<seats.size(); i++) {
            if(seats[i] == 0){
                int min_next = closestOnLeft[i]>closestOnRight[i]?closestOnRight[i]:closestOnLeft[i];
                ans = min_next>ans?min_next:ans;
            }
        }
        return ans;
    }
};
