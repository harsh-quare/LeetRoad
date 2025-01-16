class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            arr.push_back(val);
            mp[val] = arr.size()-1;
            return true;
        }
        else return false;
    }
    
    bool remove(int val) {
        if(arr.size() == 0 || mp.find(val) == mp.end()){
            return false;
        }
        else{
            if(mp[val] == arr.size()-1 || arr.size() == 1){
                arr.pop_back();
                mp.erase(val);
            }
            else{
                int id = mp[val];
                int last = arr.back();
                arr.pop_back();
                mp.erase(val);
                arr[id] = last;
                mp[last] = id;
            }
            // if(arr.size() == 0){
            //     arr[id] = last;
            //     mp[last] = id;
            // }
            return true;
        }
    }
    
    int getRandom() {
        int num = arr[rand() % arr.size()];
        return num;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */