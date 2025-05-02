class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();

        vector<int> leftClosestR(n), rightClosestL(n);

        // left to right for leftClosestR
        for(int i = 0; i < n; i++){
            if(d[i] == 'R') leftClosestR[i] = i;
            else if(d[i] == '.') leftClosestR[i] = i > 0 ? leftClosestR[i-1] : -1;
            else leftClosestR[i] = -1;  // i == 0
        }

        // right to left for rightClosestL
        for(int i = n-1; i >= 0; i--){
            if(d[i] == 'L') rightClosestL[i] = i;
            else if(d[i] == '.') rightClosestL[i] = i < n-1 ? rightClosestL[i+1] : -1;
            else rightClosestL[i] = -1; // i == n-1
        }

        string ans(n, ' ');
        for(int i = 0; i < n; i++){
            if(leftClosestR[i] == -1 && rightClosestL[i] == -1) ans[i] = '.';
            else if(leftClosestR[i] == -1){
                ans[i] = 'L';
            }
            else if(rightClosestL[i] == -1){
                ans[i] = 'R';
            }
            else{
                int dist1 = abs(i - leftClosestR[i]);
                int dist2 = abs(i - rightClosestL[i]);

                if(dist1 == dist2) ans[i] = '.';
                else if(dist1 < dist2) ans[i] = 'R';
                else ans[i] = 'L';
            }
        }

        return ans;
    }
};

// har point pe closest towards right wle 'L' se and closest towards right wale 'R' se impact pad skta h, and nett uska hoga jiska force jyada h, ya fir jiski distance uss point se kam h
