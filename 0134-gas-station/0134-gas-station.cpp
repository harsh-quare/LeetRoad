class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0;
        int totalCost = 0;

        int curFuel = 0;
        int start_id = 0;

        for(int i = 0; i < n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
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

        if(totalGas < totalCost) return -1;

        return start_id;
    }
};