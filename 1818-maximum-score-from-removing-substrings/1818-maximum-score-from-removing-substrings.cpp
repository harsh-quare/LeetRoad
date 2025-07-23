class Solution {
public:
    string removeSubstr(string& s, string& matchStr){
        stack<char> st;

        for(char& c: s){
            if(c == matchStr[1] && !st.empty() && st.top() == matchStr[0]){
                st.pop();
            }
            else{
                st.push(c);
            }
        }

        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int ans = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        // string minStr = (x < y) ? "ab" : "ba";
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