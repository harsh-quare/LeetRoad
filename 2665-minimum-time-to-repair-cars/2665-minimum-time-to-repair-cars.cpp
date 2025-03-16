class Solution {
public:
    bool canRep(long long mid, vector<int>& ranks, int cars){
        long long carsRepaired = 0;

        for(int& r: ranks){
            carsRepaired += sqrt(mid / r);

            if(carsRepaired >= cars) return true;
        }
        
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 0;
        long long high = (long long)*max_element(ranks.begin(), ranks.end())*cars*cars;

        long long res = -1;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            if(canRep(mid, ranks, cars)){
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return res;
    }
};

// time = rank * n^2
// we need to calculate if we can somehow manage to repair 'cars' number of cars in 'time' time and all the ranks given
// n = sqrt(time / rank)
// 'time' is constant, rank changes for each mechanic, hence 'n' number of cars repaired by each mechanic gets calculated
// Then it's valid

// Binary search on "ANSWER"
// Answer: whatever we need to maximize/minimize in the problem
// Uspe binary search apply kro, yaha time h
// to try to solve the canrep function in terms of "can you repair all the cars in 'mid' time"