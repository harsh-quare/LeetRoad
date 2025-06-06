class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> suffMin(n, s[n-1]);
        for(int i = n-2; i >= 0; i--) suffMin[i] = min(suffMin[i+1], s[i]);

        string t;
        string ans;

        int i = 0;
        while(i < n){
            if(t.empty() || suffMin[i] < t.back()){
                t.push_back(s[i]);
                i++;
            }
            else{
                ans.push_back(t.back());
                t.pop_back();
            }
        }

        // bachi hui string 't' me se characters ans me daal do, but hame peeche se daalne h, to reverse krke append krdo
        reverse(t.begin(), t.end());
        ans += t;

        return ans;
    }
};