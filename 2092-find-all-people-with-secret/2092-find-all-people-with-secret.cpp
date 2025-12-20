class Solution {
using pii = pair<int, int>;
const int INF = INT_MAX;
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pii>> adj(n);
        for(auto& meeting: meetings){
            int p1 = meeting[0];
            int p2 = meeting[1];
            int time = meeting[2];

            adj[p1].push_back({p2, time});
            adj[p2].push_back({p1, time});
        }

        vector<int> knowTime(n, INF);

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
    
        vector<int> res;
        while(!pq.empty()){
            int pqTime = pq.top().first;
            int person = pq.top().second;
            pq.pop();

            if(knowTime[person] != INT_MAX) continue;

            // if does not know
            knowTime[person] = pqTime;
            res.push_back(person);

            for(auto& pr: adj[person]){
                int time = pr.second;
                int nbr = pr.first;
                if(knowTime[nbr] == INF && time >= pqTime){
                    pq.push({time, nbr});
                }
            }
        }

        return res;

    }
};