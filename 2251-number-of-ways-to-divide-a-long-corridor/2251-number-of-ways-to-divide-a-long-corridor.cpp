class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> seatIndices;

        //Collect the indices of all 'S' in the corridor
        for(int i = 0; i < n; i++){
            if(corridor[i] == 'S'){
                seatIndices.push_back(i);
            }
        }

        //if the total number of seats is not even or less than 2, return 0
        int totalSeats = seatIndices.size();
        if(totalSeats < 2 || totalSeats % 2 != 0){
            return 0;
        }

        //calculate the number of ways to partition the corridor
        int ans = 1;
        for(int i = 2; i < totalSeats; i += 2){
            // started from 2, because 0,1 are in one section
            // and we check number of plants between 2 and 1, next time, 4 and 3, i.e. after every section of 2 seats
            int gap = seatIndices[i] - seatIndices[i - 1]; //gap between consecutive partitions
            ans = (1LL * ans * gap) % mod;
        }

        return ans;
    }
};
