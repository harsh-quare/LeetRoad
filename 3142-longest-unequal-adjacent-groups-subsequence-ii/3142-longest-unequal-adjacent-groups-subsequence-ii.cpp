class Solution {
public:
    bool validHammingDist(string& x, string& y){
        int cnt = 0;
        for(int i = 0; i < x.size(); i++){
            if(x[i] != y[i]) cnt++;
            if(cnt > 1) return false;
        }
        return cnt == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        
        int longestSub = 0;
        int lisIdx = 0;  // index 0 is the first such lisIdx

        vector<int> parent(n, -1);
        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(groups[i] != groups[j] && words[i].length() == words[j].length() && validHammingDist(words[i], words[j])){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;

                        if(longestSub < dp[i]){
                            longestSub = dp[i];
                            lisIdx = i;
                        }
                    }
                }
            }
        }

        vector<string> ans;
        while(lisIdx != -1){
            ans.push_back(words[lisIdx]);
            lisIdx = parent[lisIdx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// I want longest "logic" subseq
// I want to print that subseq

// What I can do is while building that lis dp array, where dp[i] is the length of longest subseq ending at index i
// I can maintain what is the prev Idx that contributed to longest subseq ending at current index
// And also I can track the latest index where I got the longest subseq till now.