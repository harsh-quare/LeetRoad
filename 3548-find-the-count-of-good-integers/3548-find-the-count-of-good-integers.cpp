class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        
        int halfLen = (n+1)/2;  // we are only trying to build the left half of the final string, right half will just be the copy of this half
        int start = pow(10, halfLen - 1);  // 100
        int end = pow(10, halfLen) - 1;  // 999

        unordered_set<string> st;  // will store all the k-pal strings having n digits

        for(int num = start; num <= end; num++){
            string leftHalf = to_string(num);
            string full = "";

            if(n % 2 != 0){
                string rightHalf = leftHalf.substr(0, halfLen-1);
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }
            else{
                string rightHalf = leftHalf;
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
            }

            long long number = stoll(full);

            if(number % k == 0){
                sort(full.begin(), full.end());
                st.insert(full);
            }
            else{
                continue;
            }
        }

        // precompute the factorials of the numbers
        vector<long long> factorial(11, 1);
        for(int i = 1; i < 11; i++){
            factorial[i] = factorial[i-1] * i;
        }


        // step-2: check all the unique k-pal strings and calculate unique permutations of each string
        long long ans = 0;
        for(const string& s: st){
            unordered_map<char, int> mp;  // store each digit frequency
            for(const char& ch: s){
                mp[ch]++;
            }

            int totalSpots = s.length();
            int zeros = mp['0'];
            int nonZeroSpots = totalSpots - zeros;

            long long perm = nonZeroSpots * factorial[totalSpots - 1];  // at first place, we cant place 0, so there are nonZeroSpots number of options at first place, and for remaining part of the string, we can have factorial[totalSpots-1] ways.
            // handling the duplicate digits
            for(int i = 0; i <= 9; i++){
                perm /= factorial[mp[i + '0']];  // 3 occ of a digit means x! / 3!
            }

            ans += perm;
        }

        return ans;
    }
};