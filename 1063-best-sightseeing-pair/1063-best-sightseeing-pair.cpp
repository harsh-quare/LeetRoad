class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int prevMax = values[0] + 0; //v[i] + i
        int maxi = INT_MIN;

        for(int j = 1; j < values.size(); j++){
            maxi = max(maxi, prevMax + values[j] - j);

            if(values[j] + j > prevMax){
                prevMax = values[j] + j;
            }
            
        }

        return maxi;
    }
};