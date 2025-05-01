class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        // can I complete smallest k tasks => use best 'k' workers
        multiset<int> ws(workers.end() - k, workers.end());

        // pahle bada task complete krne ki koshish kro, qki let's say task tha 1, usne find kiya ki 3 str. wala worker available h, but ye combo optimal nhi h, hame to iss 1 wale ko pill deke 0 bna ke fir 0 wale worker ko dena optimal krna tha. To isliye ham bade task se chhote task ki taraf aayenge
        for(int i = k-1; i >= 0; i--){
            int task = tasks[i];

            auto it = ws.lower_bound(task);
            if(it != ws.end()){
                // try without pill
                ws.erase(it);
            }
            else{
                // try a pill 
                it = ws.lower_bound(task - strength);
                if(it == ws.end() || pills == 0) return false;
                ws.erase(it);
                pills--;
            }
        }

        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        // try to assign first k smallest tasks to workers
        int low = 0, high = min(n, m);
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canAssign(mid, tasks, workers, pills, strength)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};