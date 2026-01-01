class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for(int i = n-1; i >= 0; i--){
            int newNum = (digits[i] + carry);
            digits[i] = newNum % 10;
            carry = newNum / 10;
        }

        if(carry > 0){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};