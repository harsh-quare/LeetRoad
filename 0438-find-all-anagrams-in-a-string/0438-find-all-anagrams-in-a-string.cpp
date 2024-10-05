class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        int n = s1.size();
        int m = s2.size();
        if(m<n) return {};
        vector<int> v(26,0);
        for(int i=0; i<n; i++){
            int idx = s1[i]-'a';
            v[idx]++;
        }
        vector<int> ans;
        vector<int> check(26,0);
        for(int i=0; i<n; i++){
            int idx = s2[i]-'a';
            check[idx]++;
        }
        if(v==check){
            ans.push_back(0);
        }
        int i=0,j=n;
        
        while(j<m){
           int idx1 = s2[i]-'a';
           int idx2 = s2[j] - 'a';
           check[idx2]++;
           check[idx1]--;
           i++;
           j++;
           if(check==v) ans.push_back(i);
        }
        return ans;
    }
};