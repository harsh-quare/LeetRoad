class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i = 1; i <= n; i++){
            pq.push(i);  // all seats are initially unreserved
        }
    }
    
    int reserve() {
        int smallest = pq.top();
        pq.pop();
        return smallest;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */