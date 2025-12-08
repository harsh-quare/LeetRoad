class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < n; right++){
            while(st.find(s[right]) != st.end()){  // only insert right, once the previous instance of s[right] character is not in the window
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};