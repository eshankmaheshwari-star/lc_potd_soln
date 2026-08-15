class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        vector<long long>pref(n+1,0);
        for (int i = 0;i<n;i++)
            pref[i+1]=pref[i]+tasks[i];

        long long total = pref[n];
        long long progress = 0;

        vector<int> ans;

        for (long long x:shifts) {
            if (progress+x>=total) {
                ans.push_back(0);
                progress=0;
            } else {
                progress+=x;
                int completed=upper_bound(pref.begin(),pref.end(),progress) -pref.begin()- 1;
                ans.push_back(n-completed);
            }
        }

        return ans;
    }
};