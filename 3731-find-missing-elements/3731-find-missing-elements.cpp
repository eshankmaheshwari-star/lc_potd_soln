class Solution {
public:
    vector<int> findMissingElements(vector<int>& a) {
        sort(a.begin(),a.end());
        //map<int,int> mp;
        // int maxi=INT_MIN,mini=INT_MAX;
        // for(int x:a){ 
        //     maxi=max(maxi,x);
        //     mini=min(mini,x);
        //     mp[x]++;}
        int n=a.size();
        vector<int> ans;
        int j=0;
        for(int i=a[0];i<=a[n-1];i++){
           // if(mp[i]==0) ans.push_back(i);
           if(i==a[j]) j++;
           else ans.push_back(i);
        }
        return ans;
    }
};