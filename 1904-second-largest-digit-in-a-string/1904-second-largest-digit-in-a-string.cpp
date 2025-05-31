class Solution {
public:
    int secondHighest(string s) {
        int maxi = -1;
        int secondMaxi = -1;

        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int curr = s[i] - '0';

                if(curr > maxi){
                    secondMaxi = maxi;
                    maxi = curr;
                }
                else if(curr > secondMaxi && curr < maxi) 
                    secondMaxi = curr;
            }
        }

        return secondMaxi;
    }
};