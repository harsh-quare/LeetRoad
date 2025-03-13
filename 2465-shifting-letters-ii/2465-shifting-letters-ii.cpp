class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // The method is called Difference array
        // In this method, we apply some update queries to an array or string
        // And finally we return the modified array

        int n = s.size();
        vector<int> diff(n, 0);
        for(auto v: shifts){
            int l = v[0];
            int r = v[1];
            int x = v[2];

            // What we do is, take the cummulative sum after all the queries are applied.
            // So, for that reason, we do, arr[l] += x and arr[r+1] -= x.

            if(x == 1){
                diff[l] += 1;
                if(r+1 < n) diff[r+1] -= 1;
            }
            else if(x == 0){
                diff[l] += -1;
                if(r+1 < n) diff[r+1] -= -1;
            }
        }

        int cumSum = 0;
        for(int i = 0; i < n; i++){
            cumSum += diff[i];
            cumSum %= 26;
            if(cumSum < 0) cumSum += 26;
            int k = (s[i] - 'a' + cumSum) % 26;
            s[i] = 'a' + k;
        }

        return s;
    }
};