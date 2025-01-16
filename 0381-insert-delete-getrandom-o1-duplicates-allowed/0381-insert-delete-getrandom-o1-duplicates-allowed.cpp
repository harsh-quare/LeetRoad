class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> mp; // val -> indexes
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        arr.push_back(val);
        mp[val].insert(arr.size()-1);
        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }
        else{
            int randomId = *mp[val].begin();
            mp[val].erase(randomId);
            int last = arr.back();
            arr[randomId] = last;
            mp[last].insert(randomId);
            mp[last].erase(arr.size()-1);
            arr.pop_back();
            if(mp[val].size() == 0) mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int num = arr[rand() % arr.size()];
        return num;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */