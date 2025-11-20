class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int n1 = intervals[0][1];
        int n2 = n1 - 1;

        int cnt = 2;

        for(int i = 1; i < intervals.size(); i++){
            int l = intervals[i][0];
            int r = intervals[i][1];

            if(l <= n2) continue;

            if(n1 < l){
                cnt += 2;
                n1 = r;
                n2 = r-1;
            }
            else{
                cnt++;
                n2 = n1;
                n1 = r;
            }
        }

        return cnt;
    }
};