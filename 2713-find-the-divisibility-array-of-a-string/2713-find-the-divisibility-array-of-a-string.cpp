class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans(n);

        //Divisible means remainder should be zero,
        //for every index, keep on checking the remainder till last index and remainder with current index

        int rem = 0;
        for(int i = 0; i < n; i++){
            int dig = word[i] - '0';
            long long toCheck = ((long long)rem*10 + dig) % m;
            if(toCheck == 0){
                ans[i] = 1;
                rem = 0;
            }
            else{
                ans[i] = 0;
                rem = toCheck;
            }
            // cout << rem << endl;
        }

        return ans;
    }
};