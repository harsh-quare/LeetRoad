class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        int cntS = 0;
        int ans = 1;

        int i = 0;
        while(i < corridor.size()){
            cntS += (corridor[i] == 'S');

            if(cntS != 0 && cntS % 2 == 0){
                int j = i+1;
                while(j < corridor.size() && corridor[j] == 'P'){
                    j++;
                }

                if(j != corridor.size()) ans = (1LL * ans * (j-i)) % mod;
                i = j;
            }
            else{
                i++;
            }
        }

        if(cntS == 2) return 1;
        else if(cntS % 2 != 0 || cntS == 0) return 0;
        else return ans % mod;
    }
};

// if cntSeats % 2 != 0 => return 0
// if cntSeats == 2 => return 1
// else 

// SSPPSPSPPPSPPS => 3*4*1 => 12