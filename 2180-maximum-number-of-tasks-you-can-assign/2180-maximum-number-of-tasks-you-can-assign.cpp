class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength){
        // can I complete smallest k tasks => use best 'k' workers
        multiset<int> ws(workers.end() - k, workers.end());  // pick k strongest workers

        // pahle bada task complete krne ki koshish kro without using any pills, qki let's say task tha 1, usne find kiya ki 3 str. wala worker available h, but ye combo optimal nhi h, hame to iss 1 wale ko pill deke 0 bna ke fir 0 wale worker ko dena optimal krna tha. To isliye ham bade task se chhote task ki taraf aayenge, and agar koi bada task nhi ho pata h without pill, to find karo smallest worker jisko pill deke ye task complete ho skta h
        for(int i = k-1; i >= 0; i--){
            int task = tasks[i];

            // strongest worker ko strongest task do, without any pill
            auto it = prev(ws.end());  // strongest worker
            if(task <= *it){
                ws.erase(it);
            }
            else if(pills <= 0){
                return false;
            }
            else{
                // find the weakest worker, jisko pills denge to ye strongest task ko kr dega
                auto weakestWorkrIt = ws.lower_bound(task - strength);
                if(weakestWorkrIt == ws.end()){
                    return false;
                }

                pills--;
                ws.erase(weakestWorkrIt);
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