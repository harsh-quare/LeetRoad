class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k == 1) return 'a';

        int n = operations.size();
        long long len = 1;
        long long newK = -1;
        int operationType = -1;

        for(int i = 0; i < n; i++){
            len *= 2;

            //the length is doubled after every operation
            //we keep doubling the length until we don't have minimum length of k
            //as soon as we get the len>=k, we save its operationType and we know that the character can be found out 
            //recursively by using the operationType, if its 0, the character will be same or otherwise it wil be ch+1
            //and we can get this character by taking the reference of character at k-(len/2) i.e. the guy in the first part of string
            if(len >= k){
                operationType = operations[i];
                newK = k - len/2;
                break;
            }
        }

        char ch = kthCharacter(newK, operations);

        if(operationType == 0){
            return ch;
        }
        else{
            return ch == 'z' ? 'a' : ch+1;
        }
    }
};