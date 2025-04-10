#define ll long long
ll dp[17][2];

ll find( string &num, int pos, int stat, string &suf, int limit){
    if(pos == num.length())
        return 1;

    if(num.length() < suf.length())
        return 0;

    ll ans = 0;
    int rem = num.length() -  pos;

    if(dp[pos][stat]!=-1)
        return dp[pos][stat]; 

    if(rem <= suf.length()){
        int currind = suf.length() - rem;
        char curr = suf[currind];

        if(stat == 1)
            return 1;

        else{
            if(curr > num[pos])
                return 0;

            else if(curr == num[pos])
                ans+=find(num, pos+1, 0, suf, limit);

            else
                ans+=find(num, pos+1, 1, suf, limit);
        }
    }

    else{
        int curr = (num[pos] - '0');

        if(stat == 1){
            for(int i=0; i<=limit ; ++i)
                ans+=find(num, pos+1, 1, suf, limit);
        }

        else{

            for(int i=0; i<=limit && i<=curr ; ++i){
                if(i!=curr)
                    ans+=find(num, pos+1, 1, suf, limit);

                else
                    ans+=find(num, pos+1, 0, suf, limit);
            }
        }
    }

    return dp[pos][stat] = ans;
}

class Solution {
public:
    long long numberOfPowerfulInt(long long l, long long r, int limit, string s) {

        string ls = to_string(l-1);
        string rs = to_string(r);

        ll res1 = find(ls, 0, 0, s, limit);
        memset(dp, -1, sizeof(dp));

        ll res2 = find(rs, 0, 0, s, limit);
        memset(dp, -1, sizeof(dp));

        return res2 - res1;
    }
};









