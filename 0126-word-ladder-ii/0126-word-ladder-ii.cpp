class Solution {
public:
unordered_map<string,int> mp;
vector<vector<string>> ans;
string end;
void dfs(string s,vector<string>& seq){
    if(s==end){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    int stp=mp[s];
    for(int i=0;i<s.size();i++){
                char org=s[i];
                for(char c='a';c<='z';c++){
                    s[i]=c;
                    if(mp.find(s)!=mp.end() && mp[s]+1==stp){
                        seq.push_back(s);
                        dfs(s,seq);
                        seq.pop_back();
                    }
                }
                s[i]=org;
        }
}
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
        int m=wl.size();
        queue<string> s;
        end=bw;
        //vector<vector<string>> ans;
        unordered_set<string> us(wl.begin(),wl.end());
        mp[bw]=1;
        int sz=bw.size();
        if(us.find(bw)!=us.end()) us.erase(bw);
        if(us.find(ew)==us.end()) return ans;
        queue<string> q;
        q.push(bw);
        while(!q.empty()){
            string s=q.front();
            q.pop();
            int steps=mp[s];
            if(s==ew) break;
            for(int i=0;i<sz;i++){
                char org=s[i];
                for(char c='a';c<='z';c++){
                    s[i]=c;
                    if(us.find(s)!=us.end()){
                        q.push(s);
                        us.erase(s);
                        mp[s]=steps+1;
                    }
                }
                s[i]=org;
            }
        }
        vector<string> seq;
        seq.push_back(ew);
        dfs(ew,seq);
        // queue<vector<string>> q;
        // vector<string> usedlvl;
        // q.push({bw});
        // int lvl=0;
        // while(!q.empty()){
        //     vector<string> vec=q.front();
        //     q.pop();
        //     if(vec.size()>lvl){
        //         lvl++;
        //         for(string s:usedlvl){
        //             us.erase(s);
        //         }
        //         usedlvl.clear();
        //     }
        //     string s=vec.back();
        //     if(s==ew){
        //         if(ans.size()==0) ans.push_back(vec);
        //         else if(ans[0].size()==vec.size()) ans.push_back(vec);
        //     }
        //     for(int i=0;i<s.size();i++){
        //         char org=s[i];
        //         for(char c='a';c<='z';c++){
        //             s[i]=c;
        //             if(us.find(s)!=us.end()){
        //                 vec.push_back(s);
        //                 usedlvl.push_back(s);
        //                 q.push(vec);
        //                 vec.pop_back();
        //             }
        //         }
        //         s[i]=org;
        //     }
        // }
        return ans;
    }
};