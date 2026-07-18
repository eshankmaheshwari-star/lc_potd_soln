class Solution {
public:
//can be solved as dp if thinked properly
int lhist(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        int maxA=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxA=max(maxA,arr[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
               int ele=st.top();
                st.pop();
               int nse=n;
                int pse=st.empty()?-1:st.top();
                maxA=max(maxA,arr[ele]*(nse-pse-1));
        }
        
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        int maxA=0;
        int n=mat.size();
        int m=mat[0].size();
        if(mat.empty()) return 0;
        // vector<vector<int>> psum(n, vector<int>(m,0));
        // for(int j=0;j<m;j++){
        //     int sum=0;
        //     for(int i=0;i<n;i++){
        //         if(mat[i][j]=='0') sum=0;
        //         else sum++;
        //         psum[i][j]=sum;
        //     }
            
        // }
        vector<int> psum(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1') psum[j]++;
                else psum[j]=0;
            }
            maxA=max(maxA,lhist(psum));
        }
        return maxA;
    }
};