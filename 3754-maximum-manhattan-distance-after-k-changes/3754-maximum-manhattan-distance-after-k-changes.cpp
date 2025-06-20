class Solution {
public:
    int maxDistance(string s, int k) {
        int east = 0, south = 0, west = 0, north = 0;

        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;
            else if(s[i] == 'E') east++;
            else if(s[i] == 'W') west++;

            int curDist = abs(east-west) + abs(north-south);

            int curSteps = i + 1;
            int wastedSteps = curSteps - curDist;

            // agar wastedSteps == 0 => best case scenario, ham max distance pe hi h,
            int extra = 0;
            if(wastedSteps != 0){  // kuch steps hamne waste kiye h, to unko recover krne ke liye k(power) ka use krenge, and ek baar use krne se hame 2 distance mil skti h
                // curSteps != curDist
                extra = min(2*k, wastedSteps);
            }

            int finalCurDist = curDist + extra;

            ans = max(ans, finalCurDist);
        }

        return ans;
    }
};