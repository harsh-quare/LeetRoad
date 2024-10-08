class Solution {
public:
    int minSwaps(string s) {
        if(s.size() == 0) return 0;

        // har 2 criminals me se ek ko sahi krna h, dusra wala apne aap sahi ho jayega
        // ]]] me agar pahlo ko sahi kr diya, to dusra apne aap valid ho gya, fir bas 3rd ko sahi krne ki jarurat h
        // ]]]] agar yahi aisa hota, to hame 1st ko and 3rd ko sahi krna pdta

        int imbalance = 0;
        int maxImbalance = 0;
        
        for(char c: s){
            if(c == '['){
                imbalance--;
            } 
            else{
                imbalance++;
            }
            maxImbalance = max(maxImbalance, imbalance);
        }

        return (maxImbalance + 1) / 2;
    }
};