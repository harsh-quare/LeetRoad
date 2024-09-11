class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;

        for(int i = 31; i >= 0; i--){
            bool ba = a & (1 << i);
            bool bb = b & (1 << i);

            bool bc = c & (1 << i);

            if(bc == 1){
                if(ba == 0 && bb == 0) cnt++;
            }
            else{ //agar c ki ye bit 0 h, to a and b dono ki ye bit ko 0 banana pdega and worst case me hame 2 operations lag skte h
                if(ba == 1) cnt++;
                if(bb == 1) cnt++;
            }
        }

        return cnt; 
    }
};