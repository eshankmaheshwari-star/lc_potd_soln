class Solution {
public:
vector<vector<string>> ans;
vector<string> path;
string s;
int n;
bool ispal(int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void solve(int i){
    if(i==n){
        ans.push_back(path);
        return ;
    }
    for(int j=i;j<n;j++){
        if(ispal(i,j)){
            path.push_back(s.substr(i,j-i+1));
            solve(j+1);
            path.pop_back();
        }
    }
}
    vector<vector<string>> partition(string ns) {
        s=ns;
        n=s.size();
        solve(0);
        return ans;
    }
};