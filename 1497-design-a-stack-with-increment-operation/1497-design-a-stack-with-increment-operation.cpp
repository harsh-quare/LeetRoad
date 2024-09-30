class CustomStack {
vector<int> st;
vector<int> increments;
int n;
public:
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(st.size() < n){
            st.push_back(x);
            increments.push_back(0); //no increment as of now for this index element
        }
    }
    
    int pop() {
        if(st.size() == 0) return -1;

        int idx = st.size()-1; //top element index
        if(idx > 0){
            increments[idx-1] += increments[idx];  //lazy propogation
        }

        int top = st[idx] + increments[idx];
        st.pop_back();
        increments.pop_back();

        return top;
    }
    
    void increment(int k, int val) {
        //k can be greater than st.size()'
        int idx = min(k, (int)st.size()) - 1;  //1-based to 0-based
        if(idx >= 0){
            increments[idx] += val;  //max index wale element me store kr lo and baad me usse pahle wale small indices pe lazy propagate krte jao
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