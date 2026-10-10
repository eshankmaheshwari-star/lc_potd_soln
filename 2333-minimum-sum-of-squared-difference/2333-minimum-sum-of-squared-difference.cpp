class Solution {
public:
typedef long long ll;
    long long minSumSquareDiff(vector<int>& a1, vector<int>& a2, int k1, int k2) {
        int n=a1.size();
        vector<int>diff(1e5+1,0);
        for(int i=0;i<n;i++) diff[abs(a1[i]-a2[i])]++;
        ll k=k1+k2;
        ll sum=0;
        for(int i=1e5;i>=0;i--){
            if(k<0) break;
            if(diff[i]==0) continue;
            if(diff[i]<k){
                if(i-1>=0) diff[i-1]+=diff[i];
                k-=diff[i];
                diff[i]=0;
            }
            else{
                if(i-1>=0) diff[i-1]+=k;
                diff[i]-=k;
                k=0;
            }
        }
        for(int i=1;i<=1e5;i++){
            int x=diff[i];
            while(x--) sum+=(1LL*i*i);
        }
        return sum;
    }
};