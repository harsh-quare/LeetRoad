class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // sliding window
        int n = blocks.size();
        int w = 0, b = 0;
        int ans = k; // maximum possible answer, for simplicity you can take either INT_MAX or 'n' too
        
        // first window
        for(int i = 0; i < k; i++){
            if(blocks[i] == 'W') w++;
            else b++;
        }

        ans = min(ans, w);
        
        int i = 1, j = k;
        while(j < n){
            (blocks[j] == 'W') ? w++ : b++;
            (blocks[i-1] == 'W') ? w-- : b--;

            ans = min(ans, w);
            i++;
            j++;
        }

        return ans;
    }
};