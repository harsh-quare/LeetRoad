class Solution {
public:
    string removeSubstr(string s, string& matchStr){
        // To remove substrs without using any soace
        // we take two pointers, i and j
        // i is for writing and j is for reading
        // whatever j reads, it writes it on 'i'th pointer
        // Before moving on to next read posn, 'i' checks if it has any matchStr on its left
        // if yes, then it doesn't go one by one and remove chars, but instead gets 2 places(matchString length) behind, and again start writing from here, means then j will overwrite these chars

        int i = 0;  // used for writing purpose

        for(int j = 0; j < s.length(); j++){  // 'j' is used for reading each char
            s[i] = s[j];
            i++;

            if(i >= 2 && s[i-2] == matchStr[0] && s[i-1] == matchStr[1]){
                // found matchStr before 'i'
                i -= 2;
            }
        }
        // string made till 'i' is the final string, erase the remaining part
        s.erase(begin(s) + i, end(s));

        return s;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int ans = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (maxStr == "ab") ? "ba" : "ab";


        // First pass: delete all maxStrs
        string temp_first = removeSubstr(s, maxStr);
        int removedPairs = (n - temp_first.length()) / 2;
        ans += removedPairs * max(x, y);

        // Second pass: delete all minStrs
        string temp_second = removeSubstr(temp_first, minStr);
        removedPairs = (temp_first.length() - temp_second.length()) / 2;

        ans += removedPairs * min(x, y);

        return ans;
    }
};