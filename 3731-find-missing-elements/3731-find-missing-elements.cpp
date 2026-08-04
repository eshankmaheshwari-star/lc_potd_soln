class Solution {
public:
    vector<int> findMissingElements(vector<int>& a) {
        //sort(a.begin(),a.end());
        map<int,int> mp;
        int maxi=INT_MIN,mini=INT_MAX;
        for(int x:a){ 
            maxi=max(maxi,x);
            mini=min(mini,x);
            mp[x]++;}
        int n=a.size();
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(mp[i]==0) ans.push_back(i);
        }
        return ans;
    }
};