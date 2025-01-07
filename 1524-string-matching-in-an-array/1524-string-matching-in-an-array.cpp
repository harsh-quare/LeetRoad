class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;

        for(int i = 0; i < n; i++){
            string s = words[i];
            for(int j = 0; j < n; j++){
                string x = words[j];

                if(i == j || x.length() < s.length()) continue;
                else{
                    int res = x.find(s);
                    if(res != string::npos){
                        ans.push_back(s);
                        break; //only ek baar bhi mil gya to enough h, baar baar agar alag string me mil rha to duplicates ho jayenge ans me
                    }
                }
            }
        }

        return ans;
    }
};