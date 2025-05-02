class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> forces(n, 0);
        int force = 0;

        // Left to right
        for(int i = 0; i < n; i++){
            if(d[i] == 'R') force = n;  // recharge with maximum force available
            else if(d[i] == 'L') force = 0;  // discharge it completely
            else force = max(force-1, 0);  // dots pe ya to previous se ek kam force ya fir agar 0 pe h to qki peeche koi nhi h to 0
            forces[i] = force;
        }

        // Right to left
        force = 0;
        for(int i = n-1; i >= 0; i--){
            if(d[i] == 'L') force = n;  // recharge with maximum force available
            else if(d[i] == 'R') force = 0;  // discharge it completely
            else force = max(force-1, 0);  // dots pe ya to previous se ek kam force ya fir agar 0 pe h to qki peeche koi nhi h to 0
            forces[i] -= force;
        }

        string ans;
        for(int f: forces){
            if(f == 0) ans += '.';
            else if(f > 0) ans += 'R';
            else ans += 'L';
        }

        return ans;
    }
};