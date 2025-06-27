class Solution {
public:
    bool existsKtimes(string& temp, string& s, int k){
        string str;
        while(k--) str += temp;

        // ab check krlo ki ye str, 's' ka subseq h ki nhi
        int j = 0;  // pointer of subseq
        for(int i = 0; i < s.size(); i++){
            if(s[i] == str[j]){
                j++;
            }
            if(j == str.size()) break;
        }

        return j == str.size();
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        // Better
        int n = s.size();

        vector<int> freq(26, 0);
        for(char c: s) freq[c-'a']++;

        // preprocess, consider only the ones, which has enough freq present
        for(int i = 0; i < 26; i++){
            if(freq[i] < k) freq[i] = 0;
            else freq[i] = freq[i] / k;
        }

        queue<string> q;
        q.push("");  //initial string
        string ans;

        while(!q.empty()){
            string cur = q.front();
            q.pop();

            for(char c = 'z'; c >= 'a'; c--){  // reverse order me string generate krne se lexicographically larger hi milegi
                if(freq[c-'a'] == 0) continue;  // don't take the guys who can't contribute
                
                string temp = cur + c;
                
                if(existsKtimes(temp, s, k)){
                    q.push(temp); // try to append more characters to find a longer valid string

                    if(temp.size() > ans.size()){  // found longer string then update ans
                        ans = temp;
                    }
                }
            }
        }

        return ans;
    }
};

// hame ye to pta h ki, len*k <= n => len <= n/k
        // means jo longest possible subseq ki length h, woh n/k se chhoti hogi
        // ab ham characters ki freq se check kr lete h ki kon kon valid h, jisko ham apne subseq me le skte h
        // agar koi char subseq me aana chahta h, to uski freq >= k honi padegi, so that he can occur in those 'k' occ of that subseq in string
        // agar freq > k h, to ham uss char ko freq/k times use kr skte h subseq me

        // Now, we know ki konse characters ko ham include kr skte h, to ab qki hame lexicographically largest chahiye to reverse lexicographical order me saari strings bana ke original string se compare krke longest common subseq string bana ke dekh lo, agar length equal to our subseq len aati h, to yahi answer string h, otheriwise just lower lexicographical string try kro


        // brute force way is to generate all possible subsequences(using BFS) and check if that subseq occurs k times in original string