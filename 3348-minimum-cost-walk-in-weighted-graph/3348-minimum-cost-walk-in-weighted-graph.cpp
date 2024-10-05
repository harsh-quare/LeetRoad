class Solution {
public:
    void dfs(int i, vector<vector<pair<int,int>>> &adj, vector<int> &vis, int &mn, int cnt){
        vis[i] = cnt;
        for(auto x: adj[i]){
            if(vis[x.first] == -1){
                // mn=mn & x.second;
                dfs(x.first, adj, vis, mn, cnt);
            }
        }
        
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        //Basically, hame minimum cost krna h, and ham & operations kr rhe h, and ham kahi bhi ja skte h walk krte hue
        //Basic principle is ham jitna & operations krte h, utni hi value kam hoti jati h, to ham try kr rhe h ki
        //ham apne path me max means saari value le and unka & kr de jisse minimum cost milega
        //and agar nodes different component me h, tb to no issue, -1 answer ho jayega

        vector<vector<pair<int,int>>> adj(n);
        
        for(auto e: edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        vector<int> vis(n,-1);
        int cnt=-1;
        for(int i = 0; i<n; i++){
            int mn = INT_MAX;
            if(vis[i] == -1){
                cnt++;
                dfs(i, adj, vis, mn, cnt);
            }
        }

        vector<int> min_weight(cnt + 1, INT_MAX);
        for(auto e: edges){
            min_weight[vis[e[0]]]= min_weight[vis[e[0]]] & e[2]; 
        }
        vector<int> ans;
        for(auto q:query){            
            if(vis[q[0]] != vis[q[1]])
                ans.push_back(-1);
            else if(q[0] == q[1])
                ans.push_back(0);
            else ans.push_back(min_weight[vis[q[0]]]);
        }
        
        return ans;
    }
};