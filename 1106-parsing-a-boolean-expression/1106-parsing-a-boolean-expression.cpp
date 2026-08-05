class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;
        for(char c:s){
            if(c==','||c=='(') continue;

            if(c!=')') st.push(c);
            else{
                int t=0,f=0;
                while(st.top()=='t'||st.top()=='f'){
                    if(st.top()=='t') t++;
                    else f++;
                    st.pop();
                }
                char op=st.top();
                st.pop();
                if(op=='&') st.push(f ?'f':'t');
                else if(op=='!') st.push(f?'t':'f');
                else st.push(t?'t':'f');
            }
        }
        return st.top()=='t';
    }
};