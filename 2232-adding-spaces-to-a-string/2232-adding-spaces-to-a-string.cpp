class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int i = 0, j = 0;
        string ans = "";
        while(i < n){
            if(j < spaces.size() && i == spaces[j]){
                ans += " "; 
                 //yaha space add krdo and space tracking wale pointer ko next space ki jagah pahucha do
                j++;
            }
            else{
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};