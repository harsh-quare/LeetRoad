class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        unordered_map<long long, pair<int, int>> mp;
        int n = s.size();

        //precompute positions for all substrings
        for(int i = 0; i < n; i++){
            long long val = 0;

            for(int j = i; j <= min(n-1, i+32); j++){ //limit to 32 bits for binary
                val = (val << 1) + (s[j] - '0'); //convert substring to decimal
                if(!mp.count(val)){
                    mp[val] = {i, j}; //store first occurrence of this value
                }

                if(val == 0) break;  //stop early for "0..." substrings beyond the first character
            }
        }

        for(auto& q: queries){
            int first = q[0];
            int second = q[1];

            int val = first^second;
            if(mp.count(val)){
                ans.push_back({mp[val].first, mp[val].second});
            }
            else{
                ans.push_back({-1, -1});
            }
        }

        return ans;
    }
};

// val ^ first == second
// val ^ first ^ first == second ^ first
// val == first ^ second

// Now our main task is to first conver the val to binary string
// Then search it in the string, if it's present in the string, then starting position is what the find function returns and the ending position we can get using length of this val bin string
// else if it's not present, add [-1, -1]