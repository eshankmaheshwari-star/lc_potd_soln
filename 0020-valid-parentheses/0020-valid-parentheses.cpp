class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char last='*';
        int n=s.size();
        for(int i=0;i<n;i++){
            if(last=='(' && s[i]==')') st.pop();
            else if(last=='{' && s[i]=='}') st.pop();
            else if(last=='[' && s[i]==']') st.pop();
            else{
                 st.push(s[i]);
            }
            if(!st.empty()) last=st.top();
            else last=s[i];
        }
        return st.empty();
    }
};