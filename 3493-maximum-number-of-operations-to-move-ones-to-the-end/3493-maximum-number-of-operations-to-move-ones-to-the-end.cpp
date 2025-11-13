class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int count = 0;           //To count the number of groups of '0's to the right of each '1'
        int result = 0;          //To store the final result

        //Traverse the string from the end to the start
        for(int i = n - 1; i >= 0; --i){
            if(s[i] == '0'){
                //Increment count only when the previous character is not '0' (indicating a new group of '0's)
                if (i == n - 1 || s[i + 1] != '0') {
                    count++;
                }
            } 
            else{
                //When we encounter '1', add the current count to the result
                result += count;
            }
        }
        return result;
    }
};