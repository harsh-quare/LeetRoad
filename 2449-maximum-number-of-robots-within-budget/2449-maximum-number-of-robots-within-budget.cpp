class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        long long i = 0, sum = 0, n = chargeTimes.size();
        multiset<int> st;

        for(int j = 0; j < n; j++){
            sum += runningCosts[j];
            st.insert(chargeTimes[j]);
            
            if(*rbegin(st) + (j-i+1)*sum > budget){
                // try smaller
                sum -= runningCosts[i];
                st.erase(st.find(chargeTimes[i]));  // the way to delet only one instance of an element from multiset in case of duplicates
                i++;
            }
        }

        return n-i;
    }
};