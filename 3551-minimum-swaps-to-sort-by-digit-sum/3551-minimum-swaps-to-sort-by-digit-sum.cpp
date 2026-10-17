class Solution {
public:
    int minSwaps(vector<int>& a) {
        vector<int> b=a;
        int n=a.size();
        sort(a.begin(), a.end(), [&](const int &a, const int &b) {
            int x = 0, y = 0;
            int p = a, q = b;
            while (p > 0) {
                x += p % 10;
                p /= 10;
            }
            while (q > 0) {
                y += q % 10;
                q /= 10;
            }
            if (x == y) return a < b;
            return x < y;
        });
        map<int,int>mp1,mp2;
        for(int i=0;i<n;i++) mp1[b[i]]=i;
        for(int i=0;i<n;i++) mp2[i]=mp1[a[i]];
        int cnt=0;
        vector<int> check(n,0);
        for(int i=0;i<n;i++){
            if(!check[i]){
                int len=0;
                int x=i;
                while(!check[x]){
                    len++;
                    check[x]=1;
                    x=mp2[x];
                }
                cnt+=(len-1);
            }
        }
        return cnt;
    }
};