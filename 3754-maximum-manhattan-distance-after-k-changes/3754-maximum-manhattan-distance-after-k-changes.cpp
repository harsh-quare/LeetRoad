class Solution {
public:
    int solve(string& s, int k, char vert, char horz){
        int maxi = 0;
        int dist = 0;
        for(char c: s){
            if(c == 'N' || c == 'S'){
                if(c == vert) dist++;
                else{
                    if(k > 0){
                        k--;
                        dist++;
                    }
                    else dist--;
                }
            }
            else if(c == 'E' || c == 'W'){
                if(c == horz) dist++;
                else{
                    if(k > 0){
                        k--;
                        dist++;
                    }
                    else dist--;
                }
            }

            maxi = max(maxi, dist);
        }

        return maxi;
    }
    int maxDistance(string s, int k) {
        // trying all possible combinations: NE, NW, SE, SW
        int ans = 0;
        ans = max(ans, solve(s, k, 'N', 'E'));
        ans = max(ans, solve(s, k, 'N', 'W'));
        ans = max(ans, solve(s, k, 'S', 'E'));
        ans = max(ans, solve(s, k, 'S', 'W'));

        return ans;
    }
};