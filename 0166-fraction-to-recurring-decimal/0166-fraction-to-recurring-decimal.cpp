class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";

        string ans;

        if((long long)numerator * (long long)denominator < 0) ans += "-";

        long long absNumr = labs(numerator);
        long long absDenm = labs(denominator);

        long long intDiv = absNumr / absDenm;

        ans += to_string(intDiv);

        long long rem = absNumr % absDenm;
        if(rem == 0) return ans;

        ans += ".";

        unordered_map<int, int> mp;  // rem -> index
        while(rem != 0){
            if(mp.count(rem)){
                ans.insert(mp[rem], "(");  // if remainder repeated, means there is repetiton in fraction and we need to put ( at the starting pt and at the end
                ans += ')';
                break;
            }

            mp[rem] = ans.length();  // index is current length

            rem *= 10;  // due to '.', we can take *10 each time
            int dig = rem / absDenm;
            ans += to_string(dig);

            rem = (rem % absDenm);
        }

        return ans;
    }
};