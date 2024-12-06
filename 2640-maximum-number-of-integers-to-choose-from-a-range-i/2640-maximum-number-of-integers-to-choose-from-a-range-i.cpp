class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        for(auto& x: banned){
            if(x <= n) st.insert(x);
        }
        int i = 1;
        long sum = 0;
        int cnt = 0;
        while(i <= n){
            if(st.find(i) == st.end()){
                if(sum + i > maxSum) break;
                sum += i;
                cnt++;
                i++;
            }
            else{
                i++;
            }
        }

        return cnt;
    }
};