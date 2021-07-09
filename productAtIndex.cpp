vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{
    int n;
    n = intVector.size();
    vector<int> ans;
    int forward[n];
    int backward[n];
    forward[0] = intVector[0];
    backward[n-1] = intVector[n-1];
    for(int i=1; i<n; i++) {
        forward[i] = forward[i-1]*intVector[i];
    }
    for(int i=n-2; i>=0; i--) {
        backward[i] = backward[i+1]*intVector[i];
    }
    ans.push_back(backward[1]);
    for (int i=1; i<n-1; i++) {
        ans.push_back(forward[i-1]*backward[i+1]);
    }
    ans.push_back(forward[n-2]);
    for (int i=0; i<n; i++)
        cout<<ans[i]<< " ";
    return ans;
}
