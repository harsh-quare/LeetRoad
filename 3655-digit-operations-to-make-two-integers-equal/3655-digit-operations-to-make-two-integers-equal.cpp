const int MAX = 1e4;
const int INF = 1e9 + 7;
vector<bool> isPrime(MAX, true);

class Solution {
public:
    vector<bool> precalc_primes(){
        isPrime[0] = isPrime[1] = false;
        for(int p = 2; p < MAX; p++){
            if(isPrime[p]){
                for(int j = 2; j * p < MAX; j++){
                    isPrime[j * p] = false;
                }
            }
        }
        return isPrime;
    }

    vector<int> neighbors(int n){
        vector<int> res;
        for(int base = 1; base <= n; base *= 10){
            int d = (n / base) % 10;
            if((d > 0)){
                res.push_back(n - base);
            }
            if((d < 9)){
                res.push_back(n + base);
            }
        }

        return res;
    }
    int minOperations(int n, int m) {
        precalc_primes();

        if(isPrime[n] || isPrime[m]) return -1;
        
        vector<int> dist(MAX, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[n] = 0;
        pq.push({dist[n], n});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d != dist[u]) continue;

            for(int v: neighbors(u)){
                if(isPrime[v]) continue;

                if(dist[v] > dist[u] + u){
                    dist[v] = dist[u] + u;
                    pq.push({dist[v], v});
                }
            }
        }

        if(dist[m] == INF) return -1;

        return m + dist[m];
    }
};