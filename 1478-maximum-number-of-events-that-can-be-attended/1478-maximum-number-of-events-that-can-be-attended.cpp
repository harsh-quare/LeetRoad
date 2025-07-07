class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq;  // minHeap => storing only endDay
        int day = events[0][0];  // first day, when we can attend an event
        int i = 0;
        int ans = 0;  // number of events attended

        while(!pq.empty() || i < n){  // either I have elements in pq or the iterator hasn't reached the end of array, I will keep looping

            if(pq.empty()) day = events[i][0];  // agar koi valid event nhi h hamare paas, to directly next event wale day pe move kr jao

            // put everyone inside pq, who is starting at current day
            while(i < n && events[i][0] == day){
                pq.push(events[i][1]);  // we only need endDay for processing
                i++;
            }

            if(!pq.empty()){
                pq.pop();  // event with earliest deadline has been attended
                ans++; // count that event
            }

            day++;

            // skip those events in pq, whose endDay < day => No longer valid, We can't attend these events, as the deadline has been passed already
            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }

        return ans;
    }
};

// For any day, if I have an option to select among events, I will choose the one that ends earlier => For every day, I need valid candidates, and I will selcet the one which has the earliest endDay => A MINHEAP??
// And will skip the events whose endDay < curDay