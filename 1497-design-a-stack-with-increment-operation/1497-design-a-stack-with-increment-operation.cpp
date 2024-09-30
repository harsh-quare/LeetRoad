class CustomStack {
int size;
int curSize;
vector<int> arr;
public:
    CustomStack(int maxSize) {
        size = maxSize;
        curSize = 0;
    }
    
    void push(int x) {
        if(curSize < size){
            arr.push_back(x);
            curSize++;
        }
        else return ;
    }
    
    int pop() {
        if(curSize == 0) return -1;
        int val = arr.back();
        arr.pop_back();
        curSize--;
        return val;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, curSize); i++){
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */