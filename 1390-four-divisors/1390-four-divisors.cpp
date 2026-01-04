class Solution {
private:
    vector<int> getDivisors(int num){
        vector<int> divisors;
        for(int i = 1; i <= sqrt(num); i++){
            if(num % i == 0){
                divisors.push_back(i);
                if(i != num/i) divisors.push_back(num/i);
            }
        }

        return divisors;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int num: nums){
            vector<int> divisors = getDivisors(num);

            if(divisors.size() == 4) {
                for(int div: divisors){
                    ans += div;
                }
            }
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