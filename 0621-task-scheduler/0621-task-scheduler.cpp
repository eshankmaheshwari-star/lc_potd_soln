class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        vector<int> mp(26,0);
        for(char c:t) mp[c-'A']++;
        priority_queue<int> pq;
        for(int i=0;i<26;i++){ 
            if(mp[i]>0) pq.push(mp[i]);
        }
        int time=0;
        while(!pq.empty()){
            int rlx=0;
            vector<int> temp;
            for(int i=0;i<=n;i++){
                if(pq.empty()) break;
                int x=pq.top();
                pq.pop();
                rlx++;
                time++;
                x--;                
                if(x>0) temp.push_back(x);
            }
            for(int x:temp) pq.push(x);
            if(!pq.empty()) time+=(n+1-rlx);
        }
        // sort(mp.rbegin(),mp.rend());
        // int time=0;
        //     while (mp[0] > 0) {
        //         int rlx = 0;

        //         for (int i = 0; i < 26 && rlx < n + 1; i++) {
        //             if (mp[i] > 0) {
        //                 mp[i]--;
        //                 rlx++;
        //                 time++;
        //             }
        //         }

        //         sort(mp.rbegin(), mp.rend());

        //         if (mp[0] > 0)
        //             time += (n + 1 - rlx);
        //     }
        return time;
    }
};