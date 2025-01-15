class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt1 = __builtin_popcount(num1);
        int cnt2 = __builtin_popcount(num2);

        // cout << cnt1 << " " << cnt2 << endl;

        if(cnt1 == cnt2) return num1;

        // We will try to put the ones at the same positions as num1(xoring same bits makes it 0), and if there are still some left, we will put them at rightmost positions, where 0's are in num1
        if(cnt1 > cnt2){
            // 1100, 10
            // We need to make the x XOR num1 minimal, so try eliminating leftmost 1's from num1, to make it smaller
            // and to eliminate those most significant 1's in num1, I need to put the 1's at same position in x, so that xor becomes 0
            // Means we need to traverse from right to left
            int ans = 0;
            // make most significant 1's to 1's
            for(int i = 31; i >= 0; i--){
                if(cnt2 == 0) break;
                if(num1 & (1 << i)){
                    // cout << i << endl;
                    cnt2--;
                    ans |= (1 << i);
                    // cout << num1 << endl;
                }
            }
            return ans;
        }
        else{
            // if cnt2 > cnt1
            // we will put all the ones in x at the same position as num1, so that after xoring, those 1's gets eliminated
            // and after that, for remaining 1's I'll be putting them at least significant positions where num1 is unset
            // All the 1's in num1 will be eliminated, we need the (cnt2-cnt1) number of unset bits from least significant side
            // traverse left to right
            int ans = 0;
            int diff = cnt2 - cnt1;
            for(int i = 0; i < 32; i++){
                if(num1 & (1 << i)){  // all the bits set in num1 will also be set in x
                    ans |= (1 << i);
                }
                else{
                    // if (num1 & (1 << i) == 0)  => set if, diff > 0
                    if(diff > 0){
                        ans |= (1 << i);
                        diff--;
                    }
                }
            }

            return ans;
        }
    }
};