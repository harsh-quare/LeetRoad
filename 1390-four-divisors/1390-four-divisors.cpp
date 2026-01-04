class Solution {
private:
        int getDivisorsSum(int num){
        int curDivSum = 0;
        int divCnt = 0;
        for(int i = 1; i*i <= num; i++){

            if(num % i == 0){
                int div1 = i;
                int div2 = num / i;

                if(div1 == div2){
                    divCnt++;
                    curDivSum += div1;
                }                
                else{
                    divCnt += 2;
                    curDivSum += div1 + div2;
                }
            }

            // check if more than 4 divisors
            if(divCnt > 4) return 0;
        }
        
        return divCnt == 4 ? curDivSum : 0;  // only when exactly 4 divisors
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int num: nums){
            int divSum = getDivisorsSum(num);

            ans += divSum;
        }

        return ans;
    }
};

// 21 => 1,3,7,21  => 21 + 7 + 3 + 1 => 32
// 4 => 1,2,4
// 7 => 1,7

// for(int i = 1; i <= sqrt(num); i++){
//     if(num % i == 0) cout << i << ", " << num/i << endl;
// }

// 36 => 1,2,3,4,6 or 36/6,36/4,36/2,36/1