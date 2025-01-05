class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        string x = s;
        sort(x.rbegin(), x.rend());
        if(x == s) return -1;

        int pivot = -1;
        for(int i = s.size()-2; i >= 0; i--){
            if(s[i+1] > s[i]){
                pivot = i;
                break;
            }
        }

        if(pivot == -1) return -1;

        for(int i = s.size()-1; i>=pivot; i--){
            if(s[i] > s[pivot]){
                swap(s[i], s[pivot]);
                break;
            }
        }

        sort(s.begin()+pivot+1, s.end());
        long long ans = 0;
        for(char ch: s){
            ans = ans*10 + (ch-'0');
        }

        if(ans > 2147483647) return -1;

        return ans;
    }
};

// smallest integer***