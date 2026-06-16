class Solution {
public:
    int getWaviness(int num){
        int waviness = 0;
        string numStr = to_string(num);

        for(int i = 1; i < numStr.size()-1; i++){
            if(numStr[i] < numStr[i-1] && numStr[i] < numStr[i+1]) waviness++;
            if(numStr[i] > numStr[i-1] && numStr[i] > numStr[i+1]) waviness++;
        }

        return waviness;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int x = num1; x <= num2; x++){
            ans += getWaviness(x);
        }

        return ans;
    }
};