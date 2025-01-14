class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);

        vector<int> f(n+1, 0);
        for(int i = 0; i < n; i++){
            f[A[i]]++;
            f[B[i]]++;
            if(i == 0) ans[i] = A[i]==B[i] ? 1 : 0;
            if(i > 0){
                ans[i] += ans[i-1];
                if(A[i] == B[i]) ans[i]++;
                else {
                    if(f[A[i]] == 2) ans[i]++;
                    if(f[B[i]] == 2) ans[i]++;
                }
            }
        }
        return ans;
    }
};