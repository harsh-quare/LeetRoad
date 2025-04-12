class Solution {
public:
    long long solve(string &tar, string inpSuf, int limit){   // it tells, how many smaller numbers 'tar' are there which has the suffix as 's' and each digit in it is at most limit

        if(tar.length() < inpSuf.length()){
            return 0;  // agar target integer ki value suffix se chhoti h
        }

        long long cnt = 0;
        string trailStr = tar.substr(tar.length() - inpSuf.length());
        // "43210" => 5
        // "12" => 2
        // 5-2 = 3rd index => "10"

        int remLen = tar.length() - inpSuf.length();

        for(int i = 0; i < remLen; i++){
            int dig = tar[i] - '0';

            if(dig <= limit){
                cnt += dig * pow(limit + 1, remLen - i - 1);
                // current index ke liye digit number of ways(0,1,...,dig-1), and remaining places par sab pe (limit+1) number of ways => that makes it (lim+1)^(remaining number of places)
            }
            else{
                // we can put limit+1 number of digits at all places
                cnt += pow(limit + 1, remLen - i);
                return cnt;  // early return, bcz complete answer has been calculated here
            }
        }

        if(trailStr >= inpSuf){
            cnt += 1;  // that one edge case, when we didn't consider the maximum possible digit, bcz we were scared to overflow the limit of overall integer, but the suff value is lesser, so we can actually use it, so +1
        }

        return cnt;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string fns = to_string(finish);
        string str = to_string(start-1);

        return solve(fns, s, limit) - solve(str, s, limit);
    }
};