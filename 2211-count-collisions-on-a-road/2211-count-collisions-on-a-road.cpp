class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int cols = n;

        int i = 0;
        while(i < n && directions[i] == 'L'){
            cols--;
            i++;
        }

        int j = n-1;
        while(j >= 0 && directions[j] == 'R'){
            cols--;
            j--;
        }

        while(i <= j){
            cols -= (directions[i] == 'S');
            i++;
        }

        return cols;

    }
};