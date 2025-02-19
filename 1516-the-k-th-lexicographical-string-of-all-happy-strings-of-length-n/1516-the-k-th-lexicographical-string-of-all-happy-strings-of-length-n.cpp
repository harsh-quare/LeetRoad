class Solution {
public:
    void solve(string& ans, int n, int k, int lastChar){
        if(n == 0) return;

        for(int i = 0; i < 3; i++){
            if(i == lastChar) continue;

            else{
                if(1<<(n-1) < k){
                    k -= (1 << (n-1));
                }
                else{
                    ans.push_back(char(i + 'a'));
                    solve(ans, n-1, k, i);
                    return ;
                }
            }
        }
    }
    string getHappyString(int n, int k) {
        if(k > 3*(1 << (n-1))) return "";

        string ans = "";
        solve(ans, n, k, -1);

        return ans;
    }
};
// Possible number of happy strings
// n=1 => 3
// n=2 => 6
// n=3 => 12
// n=4 => 24
// n=5 => 48
// Basically, 3*pow(2, n-1)