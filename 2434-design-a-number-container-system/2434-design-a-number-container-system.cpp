class NumberContainers {
public:
    unordered_map<int, int> mp1;  // index -> number
    unordered_map<int, set<int>> mp2;  //number -> indexes

    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(mp1[index] == 0){
            mp1[index] = number;
            mp2[number].insert(index);
        }
        else{
            // pahle jo pda h yaha, usko hata do
            int prevNumber = mp1[index];
            mp2[prevNumber].erase(index);

            // new entry dono map me
            mp1[index] = number;
            mp2[number].insert(index);
        }
    }
    
    int find(int number) {
        if(mp2[number].size() == 0) return -1;
        else return *mp2[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */