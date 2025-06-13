class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        if(totalGas < totalCost) return -1;
        
        int curFuel = 0;
        int start_id = 0;

        for(int i = 0; i < n; i++){
            curFuel += (gas[i] - cost[i]);

            if(curFuel < 0){
                // not a valid starting point
                start_id = i+1;
                curFuel = 0;
            }
            else{
                // consider it as starting point, and keep going
                continue;
            }
        }

        return start_id;
    }
};