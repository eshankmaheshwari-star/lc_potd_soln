class Solution {
public:
    typedef long long ll;
    
    string smallestNumber(string num, long long t) {
        vector<int> mp(8, 0);
        for (int p : {2, 3, 5, 7}) {
            while (t % p == 0) {
                mp[p]++;
                t /= p;
            }
        }
        if (t > 1) return "-1";
        
        int n = num.size();
        
        auto removefactors = [](vector<int>& c, int d) {
            if (d == 0) return;
            for (int p : {2, 3, 5, 7}) {
                while (d % p == 0) {
                    c[p] = max(0, c[p] - 1);
                    d /= p;
                }
            }
        };
        
        auto getmindigit = [](vector<int>& c) -> vector<int> {
            vector<int> d;
            int c2 = c[2], c3 = c[3], c5 = c[5], c7 = c[7];
            while(c3 >= 2) { d.push_back(9); c3 -= 2; }
            while(c2 >= 3) { d.push_back(8); c2 -= 3; }
            while(c7 >= 1) { d.push_back(7); c7 -= 1; }
            while(c3 >= 1 && c2 >= 1) { d.push_back(6); c3 -= 1; c2 -= 1; }
            while(c5 >= 1) { d.push_back(5); c5 -= 1; }
            while(c2 >= 2) { d.push_back(4); c2 -= 2; }
            while(c3 >= 1) { d.push_back(3); c3 -= 1; }
            while(c2 >= 1) { d.push_back(2); c2 -= 1; }
            sort(d.begin(), d.end());
            return d;
        };
        
        vector<vector<int>> preqreq(n + 1, vector<int>(8, 0));
        preqreq[0] = mp;
        int fzero = -1;
        
        for(int i = 0; i < n; i++) {
            int d = num[i] - '0';
            if(d == 0) {
                fzero = i;
                break;
            }
            preqreq[i + 1] = preqreq[i];
            removefactors(preqreq[i + 1], d);
        }
        
        if(fzero == -1) {
            vector<int> ans = getmindigit(preqreq[n]);
            if(ans.empty()) return num;
        }
        
        int limit = (fzero != -1) ? fzero : n - 1;
        for(int i = limit; i >= 0; i--) {
            int start = (num[i] - '0') + 1;
            for(int j = start; j <= 9; j++) {
                vector<int> remreq = preqreq[i];
                removefactors(remreq, j);
                
                vector<int> mind = getmindigit(remreq);
                int slots_left = n - 1 - i;
                if ((int)mind.size() <= slots_left) {
                    string result = num.substr(0, i);
                    result += to_string(j);
                    int ones = slots_left - mind.size();
                    result.append(ones, '1');
                    for (int digit : mind) {
                        result += to_string(digit);
                    }
                    return result;
                }
            }
        }
        
        vector<int> mind = getmindigit(mp);
        int totallen = max(n + 1, (int)mind.size());
        
        string result = "";
        int ones = totallen - mind.size();
        result.append(ones, '1');
        for (int digit : mind) {
            result += to_string(digit);
        }
        return result;
    }
};