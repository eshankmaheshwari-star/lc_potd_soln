class Solution {
public:
    int missingInteger(vector<int>& a) {
        int n=a.size(),presum=a[0];
        map<int,int> map;
        int maxi=0;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]+1) presum+=a[i];
            else break ;
        }
        for(int i=0;i<n;i++){
            map[a[i]]++;
            maxi=max(maxi,a[i]);
        }
        for(int i=presum;i<=max(maxi,presum);i++){
            if(map.find(i)==map.end()) return i;
        }
        return maxi+1;
    }
};