class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        stack<char> st;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(s[i]);
            else{
                if(st.empty()){
                    if(i<n-1 && s[i+1]==')'){
                         cnt++;
                         i++;
                    }
                    else{
                        cnt+=2;
                    }
                }
                else{
                    if(i<n-1 && s[i+1]==')'){
                        st.pop();
                        i++;
                        continue;
                    }
                    if(i==n-1 || s[i+1]!=')') cnt++;
                    else{
                        i++;
                        cnt+=2;
                    }
                    st.pop();
                }
            }
        }
        return cnt+2*st.size();
    }
};