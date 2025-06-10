class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for(char c : s){
            freq[c-'a']++;
        }

        int maxOdd = -1;
        int minEven = INT_MAX;
        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 != 0){
                maxOdd = max(maxOdd, freq[i]);
            }
            else if(freq[i] > 0){  // odd hota to if me chale jata, yaha aaya mtlb even to 100% h
                minEven = min(minEven, freq[i]);
            }
        }

        return maxOdd - minEven;
    }
};