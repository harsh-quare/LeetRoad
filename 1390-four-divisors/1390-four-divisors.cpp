class Solution {
private:
        int getDivisorsSum(int num){
        int curDivSum = 0;
        int divCnt = 0;
        for(int i = 1; i <= sqrt(num); i++){
            if(num % i == 0){
                // 1st divisor is 'i'
                divCnt++;
                curDivSum += i;
                
                // another divisor is 'num/i'
                if(i != num/i){
                    divCnt++;
                    curDivSum += num/i;
                }
            }

            // check if more than 4 divisors
            if(divCnt > 4) return 0;
        }

        if(divCnt != 4) return 0;  // in case of lesser than equal to 3 
        
        return curDivSum;
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