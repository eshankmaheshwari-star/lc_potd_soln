// #include <sstream>
// class Solution {
// public:
// vector<string> ans;
// string s;
// string path;
// long long n,k;
// long long answer(string ep){
//     stringstream ss(ep);
//     char op='+';
//     long long curr=0;
//     vector<long long> stack;
//     char ch;
//     while(ss>>curr){
//         if (op == '+') stack.push_back(curr);
//         else if (op == '-') stack.push_back(-curr);
//         else if (op == '*') stack.back() *= curr;
//         else if (op == '/' && curr!=0) stack.back() /= curr;     
//         if(!(ss>> op)) break;
//     }
//     long long total=0;
//     for(long long x:stack) total+=x;
//     return total;
// }
// void dpz(long long i,long long j){
//     if(j==n){
//         if(answer(path)==k && i==j) ans.push_back(path);
//         return;
//     }
//     if(s[i]!=0) dpz(i,j+1);

//     string sub=s.substr(i,j-i+1);
//     int r=path.size();
//     if(sub.size()>1 && sub[0]=='0') return;
//     if(i==0){
//         path+=sub;
//         dpz(j+1,j+1);
//         path.resize(r);
//     }
//     else{
//             path += "+" + sub;
//             dpz(j + 1, j + 1);
//             path.resize(r);
//             path += "-" + sub;
//             dpz(j + 1, j + 1);
//             path.resize(r);
//             path += "*" + sub;
//             dpz(j + 1, j + 1);
//             path.resize(r);
//             path += "/" + sub;
//             dpz(j + 1, j + 1);
//             path.resize(r);
//     }
// }
//     vector<string> addOperators(string num, int target) {
//         s=num;
//         k=target;
//         n=s.size();
//         dpz(0,0);
//         return ans;
//     }
// };



class Solution {
public:
    vector<string> ans;
    string s;
    string path;
    long long n, k;
    void dpz(long long i, long long j, long long curr_val, long long prev_val){
        if(j == n){
            if(i == j && curr_val == k) {
                ans.push_back(path);
            }
            return;
        }
        if (s[i] != '0') {
            dpz(i, j + 1, curr_val, prev_val);
        }
        string sub = s.substr(i, j - i + 1);
        long long num = stoll(sub);
        int r = path.size();
        if(sub.size() > 1 && sub[0] == '0') return;
        if(i == 0){
            path += sub;
            dpz(j + 1, j + 1, num, num);
            path.resize(r);
        }
        else{
            path += "+" + sub;
            dpz(j + 1, j + 1, curr_val + num, num);
            path.resize(r);
            path += "-" + sub;
            dpz(j + 1, j + 1, curr_val - num, -num);
            path.resize(r);
            path += "*" + sub;
            dpz(j + 1, j + 1, (curr_val - prev_val) + (prev_val * num), prev_val * num);
            path.resize(r);
        }
    }

    vector<string> addOperators(string num, int target) {
        ans.clear();
        path = "";
        s = num;
        k = target;
        n = s.size();
        if (n == 0) return ans;
        dpz(0, 0, 0, 0);
        return ans;
    }
};