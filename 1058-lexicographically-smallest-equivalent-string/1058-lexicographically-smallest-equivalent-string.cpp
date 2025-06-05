class Solution {
public:
    int find(vector<int>& parent, int v){
        if(parent[v] == -1) return v;
        else return parent[v] = find(parent, parent[v]);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26, -1);  // build disjoint equivalent sets, -1 means he is own parent. Keep smallest in each set as absolute parent

        for(int i = 0; i < s1.length(); i++){
            char c1 = s1[i];
            char c2 = s2[i];

            if(c1 == c2) continue;

            int par_x = find(parent, c1-'a');
            int par_y = find(parent, c2-'a');

            if(par_x == par_y) continue; // already in same set
            
            // union by smallest char as ultimate parent
            if(par_x > par_y) parent[par_x] = par_y;  // bade ko chhote se connect
            else parent[par_y] = par_x;
        }

        string ans = "";
        for(char c: baseStr){
            int par = find(parent, c-'a');
            ans.push_back(char(par+97));
        }

        return ans;
    }
};