class Solution {
public:
    string robotWithString(string s) {
        // we greedily try to write the smallest characters first
        // means, we just apply operation-1, which is to add to the stack, until we don't get a character for which no character is smaller in it's right side of the string
        // means, if I'm currently at index i, and this character is 'b', and the smallest available character to thr right in string s(from (i+1) to (n-1)) is 'd', then we will add 'b' to the answer, bcz that's the most profitable way for us

        // That's why we would need to know what is the smallest character to the right of each index in the array
        // naively it will take extra O(n) time for each index, but we can reduce it to O(1) by using some extra space and preprocess the smallest character to the right side of each index

        int n = s.size();
        vector<char> rightSmallestChar(n);  // rightSmallestChar[i] = smallest character from i to n-1, including i

        // process from right to left
        rightSmallestChar[n-1] = s[n-1];
        for(int i = n-2; i >= 0; i--){
            rightSmallestChar[i] = min(s[i], rightSmallestChar[i+1]);
        }

        stack<char> t;
        string ans = "";

        int i = 0;

        while(i < n){
            t.push(s[i]);   // apply op-1

            char minChar;
            if(i+1 < n){
                minChar = rightSmallestChar[i+1];  // bcz rightSmallestChar[i] is smallest in right including 'i' itself, but we only want smallest from right excluding itself, that's why i+1
            }
            else minChar = rightSmallestChar[i];  // last index=> nobody smaller to the right

            
            // Now apply operation-2 until the top of the 't' is having nobody on the right as smaller, means top is the smallest there is
            while(!t.empty() && t.top() <= minChar){
                ans += t.top();
                t.pop();
            }

            i++;
        }

        // bache hue characters ko daal do
        while(!t.empty()){
            ans += t.top();
            t.pop();
        }
        return ans;
    }
};