class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int i = 0, j = 0;
        multiset<int> st;
        int ans = 0;
        int n = runningCosts.size();
        long long curSum = 0;

        while(i < n && j < n){
            st.insert(chargeTimes[j]);
            curSum += runningCosts[j];
            long long cost = *st.rbegin() + (j-i+1)*curSum;

            if(cost <= budget) ans = max(ans, j-i+1);
            else{
                curSum -= runningCosts[i];
                st.erase(st.find(chargeTimes[i]));
                i++;
            }
            j++;
        }

        return ans;
    }
};