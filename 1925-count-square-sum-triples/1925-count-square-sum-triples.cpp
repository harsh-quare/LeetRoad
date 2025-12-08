class Solution {
public:
    int countTriples(int n) {
        // Method-3 => Optimal, O(nlogn), Try all possible c values and try to create pairs a,b using two pointers and binary search

        int cnt = 0;
        for(int c = 1; c <= n; c++){
            
            int tar = c*c;
            int left = 1, right = c-1;

            while(left < right){
                int sum = left*left + right*right;
                if(sum == tar){
                    cnt += 2;  // a,b and b,a
                    left++;
                    right--;
                }
                else if(sum > tar){
                    right--;
                }
                else left++;
            }
        }

        return cnt;
    }
};