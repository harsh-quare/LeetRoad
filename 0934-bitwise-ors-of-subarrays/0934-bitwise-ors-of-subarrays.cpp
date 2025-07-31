class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> all_ors;

        //this set stores the distinct OR values of all subarrays ending at the previous position (i-1).
        unordered_set<int> prev_prefs;
        for(int& x: arr){
            
            //this set will store the distinct OR values of all subarrays ending at the current position (i).
            unordered_set<int> cur_prefs;
            //subarray consisting of just the current element.
            cur_prefs.insert(x);

            //to get the ORs of other subarrays ending at the current position, we take all the ORs of subarrays ending at the previous position and apply a bitwise OR with the current element.
            for(auto& prev_or: prev_prefs){
                cur_prefs.insert(prev_or | x);
            }

            //the results for the current position become the "previous" results for the next iteration.
            prev_prefs = cur_prefs;

            //add all newly found OR values to our master set of results.
            for(auto& cur_or: cur_prefs){
                all_ors.insert(cur_or);
            }
        }

        return all_ors.size();
    }
};