#define ll long long 
ll mod = 1000000007;

vector<ll> fact; 
void calFact() {
    fact.push_back(1);
    fact.push_back(1);
    for(ll i = 2; i <= 99; i++) {
        ll v = ((fact[i-1]%mod)*(i%mod))%mod; 
        fact.push_back(v); 
    }
}
class Solution {
public:

    ll powe(ll a, ll b) {
        ll res = 1; 
        while(b) {
            if(b%2) {
                res = ((res%mod)*(a%mod))%mod; 
            }
            b/=2;
            a = ((a%mod)*(a%mod))%mod;
        }

        return res;
    }
    ll dp[81][9*41][41];

    ll helper(ll i, string &s, ll sum, ll cnt, unordered_map<int, int> &mp) {
        int n = s.size();
        if(sum == 0 && cnt == 0) {
            return 1;
        }
        if(sum < 0 || cnt < 0 || i >= n) return 0;
        if(dp[i][sum][cnt] != -1) return dp[i][sum][cnt]; 
        ll res = helper(i+1, s, sum, cnt, mp)%mod; 
        
        int num = (s[i] - '0');
        if(sum >= num && cnt > 0) {
            mp[num]++; 
            res = (res%mod + helper(i+1, s, sum - num, cnt-1, mp)%mod)%mod; 
            if(mp[num] == 1) {
                mp.erase(num);
            } else {
                mp[num]--; 
            }
        } 
        return dp[i][sum][cnt] = res; 
    }

    int countBalancedPermutations(string num) {
        if(fact.size() == 0) calFact();
        memset(dp, -1, sizeof dp);
        int totSum = 0; 
        ll n = num.size(); 
        vector<int> digs(10, 0); 
        for(int i = 0; i < n; i++) {
            totSum += (num[i]-'0');
            digs[num[i]-'0']++;
        }
        if(totSum%2) return 0; 
        unordered_map<int, int> mp;
        ll res = helper(0, num, totSum/2, n/2, mp);
    
        ll temp = ((fact[n/2]%mod)*(fact[n-(n/2)]%mod))%mod;
        res = ((res%mod)*(temp%mod))%mod;
        ll t2 = 1; 
        for(int i: digs) {
            if(i == 0) continue; 
            ll val = fact[i]; 
            t2 = ((t2%mod)*(val%mod))%mod;
        }

        temp = powe(t2, mod-2)%mod;
        return ((res%mod)*(temp%mod))%mod;
    }
};