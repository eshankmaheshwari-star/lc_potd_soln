class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int n1=to_string(low).size(),n2=to_string(high).size();
        string s="123456789";
        for(int i=n1;i<=n2;i++){
            for(int j=0;j<9-i+1;j++){
                int x=stoi(s.substr(j,i));
                if(low<=x && x<=high) ans.push_back(x);
                else if(x>high) break;
            }
        }
        return ans;
    }
};