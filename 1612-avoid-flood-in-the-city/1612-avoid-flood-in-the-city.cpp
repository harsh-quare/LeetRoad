class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        set<int> st;   // store sunny days in incr order
        unordered_map<int, int> mp;

        vector<int> ans(n, 1); //For the remaining sunny days at the end, we can drain any arbitrary lake; for convenience, we choose lake 1.
        for(int i = 0; i < n; i++){
            if(rains[i] == 0){
                st.insert(i);
            }
            else{
                ans[i] = -1;  // bcz rains[i] > 0
                if(mp.count(rains[i])){
                    auto it = st.lower_bound(mp[rains[i]]);   // find the first day greater than current day, to dry this lake
                    if(it == st.end()){  // no such day found => lake will flood for sure
                        return {};
                    }

                    ans[*it] = rains[i];   // we will dry rains[i] on the 'found' day
                    st.erase(it);
                }
                mp[rains[i]] = i;
            }
        }

        return ans;
    }
};