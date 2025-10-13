class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;

        ans.push_back(words[0]);
        
        for(int i = 1; i < n; i++){
            string prev = ans.back();
            string cur = words[i];

            sort(prev.begin(), prev.end());
            sort(cur.begin(), cur.end());

            if(cur != prev){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};