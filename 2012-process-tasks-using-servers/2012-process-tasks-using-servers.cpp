class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        //Min-heap to store free servers (sorted by weight, then by index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;

        //Min-heap to store occupied servers (sorted by free time, then by index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;

        //Initially, all servers are free
        for(int i = 0; i < n; i++){
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);
        int time = 0;

        for(int j = 0; j < m; j++){
            //Move `time` to current task's arrival time
            time = max(time, j);

            //If no free servers, jump `time` to the next available free time
            if(freeServers.empty()){
                time = occupied.top().first;
            }

            //Release all servers that are free by current `time`
            while(!occupied.empty() && occupied.top().first <= time){
                int idx = occupied.top().second;
                freeServers.push({servers[idx], idx});
                occupied.pop();
            }

            //Assign the current task to the free server with the smallest weight
            int weight = freeServers.top().first;
            int id = freeServers.top().second;
            freeServers.pop();

            //Assign the task and record which server took it
            ans[j] = id;

            //Mark the server as busy until `time + tasks[j]`
            occupied.push({time + tasks[j], id});
        }

        return ans;
    }
};
