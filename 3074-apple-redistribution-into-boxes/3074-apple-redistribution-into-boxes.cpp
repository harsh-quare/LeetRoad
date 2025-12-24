class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();

        int numApples = 0;
        for(int apl : apple) numApples += apl;

        sort(capacity.rbegin(), capacity.rend());
        int i = 0;
        while(numApples){
            numApples -= capacity[i];
            i++;
            if(numApples <= 0) return i;
        }

        return -1;
    }
};