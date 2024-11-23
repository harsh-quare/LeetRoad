class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;

        for(int i = 0; i < s.size(); i++){
            char ch1 = s[i];
            char ch2 = t[i];

            long long ans1 = 0;
            long long ans2 = 0;
            if(ch2 > ch1){
                //previous me jaoge to ghoom ke aana padega
                for(int j = ch1 - 'a'; j >= 0; j--){
                    ans1 += previousCost[j];
                }
                for(int j = 25; j > ch2-'a'; j--){
                    ans1 += previousCost[j];
                }

                for(int j = ch1-'a'; j < ch2-'a'; j++){
                    ans2 += nextCost[j];
                }
                // cout << ans1 << " " << ans2 << endl;
            }
            else{
                //next ke liye ghoom ke aana padega
                for(int j = ch1-'a'; j < 26; j++){
                    ans2 += nextCost[j];
                }
                for(int j = 0; j < ch2-'a'; j++){
                    ans2 += nextCost[j];
                }

                for(int j = ch1-'a'; j > ch2-'a'; j--){
                    ans1 += previousCost[j];
                }

                // cout << ans1 << " " << ans2 << endl;
            }

            ans += min(ans1, ans2);

            // cout << ans1 << " " << ans2 << endl;
            
        }

        return ans;
    }
};