class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = n; // given 1 candy to all
        int i = 1;

        while(i < n){

            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                ans += peak;
                i++;

                if(i == n) return ans;
            }

            int dip = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                dip++;
                ans += dip;
                i++;
            }

            ans -= min(peak, dip);  // remove min of both after one mountain ends (peak + dip), bcz we added both, and we want to keep the bigger one. 
        }

        return ans;
    }
};