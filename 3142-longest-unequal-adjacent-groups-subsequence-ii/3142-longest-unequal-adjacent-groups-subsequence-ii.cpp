class Solution {
public:
    bool checkHammingDist(string& x, string& y){
        int cnt = 0;
        for(int i = 0; i < x.size(); i++){
            cnt += (x[i] != y[i]);
            if(cnt > 1) return false;
        }
        return cnt == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // Pattern of Longest increasing subsequence(LIS) problem: longest subseq following some logic
        int n = words.size();
        int lis = 0;
        int lisIdx = 0;

        vector<int> prevIdx(n, -1);
        vector<int> lisdp(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(groups[i] != groups[j] && words[i].length() == words[j].length() && checkHammingDist(words[i], words[j])){
                    if(lisdp[i] < lisdp[j] + 1){
                        lisdp[i] = lisdp[j] + 1;
                        prevIdx[i] = j;

                        if(lis < lisdp[i]){
                            lis = lisdp[i];
                            lisIdx = i;
                        }
                    }
                }
            }
        }

        vector<string> ans;
        while(lisIdx != -1){
            ans.push_back(words[lisIdx]);
            lisIdx = prevIdx[lisIdx];
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};