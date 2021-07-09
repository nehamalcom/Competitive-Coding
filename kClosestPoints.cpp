// Easiest solution using partition_sort
bool comp (vector<int> &a, vector<int> &b) {
    return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    partition_sort(points.begin(), points.begin()+k, points.end(), comp);

    return vector<vector<int>>(points.begin(), points.begin()+k);
}

// Naive solution which will not run in end_time
/*
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<int>dist;
    vector<vector<int>>pos;
    int ctr = 0;
    int currDist;
    for (int i=0; i<points.size(); i++) {
        currDist = points[i][0]*points[i][0]+points[i][1]*points[i][1];
        if (ctr == 0) {
            dist.push_back(currDist);
            pos.push_back(points[i]);
            ctr++;
        }
        else {
            if (ctr == k) {
                if (currDist<dist[k-1]) {
                    // pop off and insert
                    dist.pop_back();
                    pos.pop_back();
                    --ctr;
                }
            }
            if(ctr<k) {
                int flag = 0;
                for (int j=0; j<ctr; j++) {
                    if(currDist<dist[j]){
                        dist.insert(dist.begin()+j, currDist);
                        pos.insert(pos.begin()+j, points[i]);
                        ctr++;
                        flag = 1;
                        break;
                    }
                }
                if(flag!=1) {
                    dist.push_back(currDist);
                    pos.push_back(points[i]);
                    ctr++;
                }
            }
        }
    }
    return pos;
}
*/
