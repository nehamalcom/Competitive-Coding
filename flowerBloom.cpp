#include <vector>
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lastDay=0;
        //calculate total number of days
        for(int i=0; i<bloomDay.size(); i++)
            if(bloomDay[i]>lastDay)
                lastDay = bloomDay[i];

        int lo = 0;
        int hi = lastDay;
        int mid;
        int ctr;
        int bouq_ctr;

        while(lo<=hi) {
            mid = (lo+hi)/2;
            //calculate the number of bouquets on the mid'th day
            cout<<endl<<"mid day: "<<mid<<endl;
            ctr = 0;
            bouq_ctr = 0;
            for(int j=0; j<bloomDay.size(); j++) {
                //cout<<endl<<"day "<<j<< " ";
                if(bloomDay[j]<=mid)
                    ctr++;
                else
                    ctr = 0;
                if(ctr == k){
                    bouq_ctr++;
                    ctr = 0;
                }
            }
            cout<<bouq_ctr;
            //do usual binary search based on your result and lessen the number of days
            if (bouq_ctr >= m) {
                ctr = 0;
                bouq_ctr = 0;
                cout<< "here";
                for(int j=0; j<bloomDay.size(); j++) {
                    //cout<<endl<<"day "<<j<< " ";
                    if(bloomDay[j]<=mid-1)
                        ctr++;
                    else
                        ctr = 0;
                    if(ctr == k){
                        bouq_ctr++;
                        ctr = 0;
                    }
                }
                if(bouq_ctr<m)
                    return mid;
                hi = mid-1;
            }
            else
                lo = mid+1;

        }
        return -1;
    }
};
