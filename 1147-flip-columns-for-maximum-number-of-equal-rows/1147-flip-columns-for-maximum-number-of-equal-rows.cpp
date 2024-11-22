class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        //two rows can be made equal if they both are either the same already or one is inverted version of another
        //we will use map to efficiently lookup and avoid repeated calculations in the array for each row
        //how to check same rows and inverted rows??
        //observe that, same rows will be following the same pattern of 0 and 1s in the row
        // while in inverted, there will be the different pattern of 0 and 1s but the pattern of changes will remain the samw
        //means there will be point of changes at the same column for both curRow and inverted rows
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp;

        for(auto& row : matrix){

            string s = "";
            int firstVal = row[0];

            for(int col = 0; col < n; col++){
                if(row[col] == firstVal){
                    s += 's';  //same
                }
                else{
                    s += 'd';  //different
                }
            }

            mp[s]++;
        }

        int ans = 0;
        for(auto& it: mp){
            ans = max(ans, it.second);
        }

        return ans;
    }
};