class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;  //wt of server, index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;  //freeTime, index

        //initially all servers are free
        for(int i = 0; i < n; i++){
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);
        int time = 0;
        for(int j = 0; j < m; j++){
            time = max(time, j);
            if(freeServers.empty() && !occupied.empty()){
                // agar saare occupied h, to hame next server uss time pe milega jab koi occupied server free hoga, to time jump kr lo, qki beech me koi event nhi ho rha
                time = occupied.top().first;
            }

            //jitne server curr time se pahle tak occupied me se free ho gye h, unko bahar nikal ke available bana do
            while(!occupied.empty() && occupied.top().first <= time){
                int idx = occupied.top().second;
                freeServers.push({servers[idx], idx});
                occupied.pop();
            }
            
            int wt = freeServers.top().first;
            int id = freeServers.top().second;
            freeServers.pop();

            ans[j] = id;
            occupied.push({time + tasks[j], id});
        }

        return ans;
    }
};