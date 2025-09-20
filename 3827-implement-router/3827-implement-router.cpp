class Router {
public:
    queue<string> q;
    unordered_map<string, vector<int>> mp;
    unordered_map<int, vector<int>> destMap;
    int limit;
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);

        if(mp.find(key) != mp.end()) return false; // duplicate packet
        if(q.size() == limit){
            forwardPacket(); // evict oldest
        }

        q.push(key);
        mp[key] = {source, destination, timestamp};
        destMap[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        string key = q.front(); 
        q.pop();
        
        vector<int> ans = mp[key];
        destMap[ans[1]].erase(destMap[ans[1]].begin()); // remove earliest timestamp for that destination
        mp.erase(key);
        return ans;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        return upper_bound(destMap[destination].begin(), destMap[destination].end(), endTime) -
                lower_bound(destMap[destination].begin(), destMap[destination].end(), startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */