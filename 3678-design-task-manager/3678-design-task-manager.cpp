class TaskManager {
    set <pair<int, pair<int, int>>> st;  // { priority, {taskId, userId}}
    map<int, pair<int, int>> mp;  // taskId -> {priority,userId}
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& v: tasks){
            int userId = v[0], taskId = v[1], priority = v[2];
            st.insert({priority, {taskId, userId}});
            mp[taskId] = {priority, userId};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {priority, userId};
        st.insert({priority, {taskId, userId}});
    }
    
    void edit(int taskId, int newPriority) {
        int prevPriority = mp[taskId].first;
        int userId = mp[taskId].second;

        // find the previous entry in set and remove it
        st.erase({prevPriority, {taskId, userId}});
        // insert the new entry
        st.insert({newPriority, {taskId, userId}});

        //update priority in map too
        mp[taskId].first = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = mp[taskId].first;
        int userId = mp[taskId].second;
        
        // remove entry from map
        mp.erase(taskId);

        // remove from set
        st.erase({priority, {taskId, userId}});
    }
    
    int execTop() {
        if(st.empty()) return -1;  // if there are no tasks
        // remove the last entry in set
        auto entry = *st.rbegin();
        int priority = entry.first;
        int taskId = entry.second.first;
        int userId = entry.second.second;

        st.erase({priority, {taskId, userId}});
        mp.erase(taskId);

        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */


// set <pair<int, pair<int, int>>> st;  // { priority, {taskId, userId}}
// unordered_map<int, pair<int, int>> mp;  // taskId -> {priority,userId}