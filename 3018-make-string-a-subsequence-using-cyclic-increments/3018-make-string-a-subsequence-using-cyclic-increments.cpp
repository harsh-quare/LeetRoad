class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        //for ecery character in str2, there must be a character in str1, which is equal or just lesser character.
        int n = str1.size();
        int m = str2.size();

        int i = 0, j = 0;
        while(i < n && j < m){
            if(str1[i] == str2[j] || str1[i] + 1 == str2[j] || str1[i] - 25 == str2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        if(j == m) return true;
        return false;
    }
};