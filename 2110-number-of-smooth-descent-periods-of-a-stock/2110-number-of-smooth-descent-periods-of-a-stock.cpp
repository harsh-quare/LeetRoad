class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int size = prices.size();

        long long result = 0;
        int left = 0;

        while(left < size){
            int right = left + 1;

            while(right < size && prices[right] == prices[right - 1] - 1){
                right++;
            }

            result += 1LL * (right - left) * (right - left + 1) / 2;

            left = right;
        }   

        return result;
    }
};

//  |
// [3,2,1,4]
//  |

// j = i+1
// while arr[j] == arr[j-1] - 1
//     j++
// ans += (j-i)*(j-i+1) / 2