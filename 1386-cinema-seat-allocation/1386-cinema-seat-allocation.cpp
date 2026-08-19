class Solution {
public:
    int maxNumberOfFamilies(int nm, vector<vector<int>>& a) {
        unordered_map<int,int> ump;
        for(auto it:a ){
            int r=it[0];
            int c=it[1];
            if(c>=2 && c<=5) ump[r]|=1; 
            if(c>=4 && c<=7) ump[r]|=2; 
            if(c>=6 && c<=9) ump[r]|=4; 
        }
        long long cnt=(nm-ump.size())*2;
        for(auto [r,m]:ump){
            if((m & 1) == 0 && (m & 4) == 0) cnt += 2;
            else if((m & 1) == 0 || (m & 2) == 0 || (m & 4) == 0) cnt++;
        }
        return cnt;
    }
};