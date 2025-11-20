class Solution {
public:
    bool n_in_range(int n, int l, int r){
        return n >= l & n <= r;
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int n1 = intervals[0][1];
        int n2 = n1 - 1;

        int cnt = 2;

        for(int i = 1; i < intervals.size(); i++){
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(!n_in_range(n1, l, r) && !n_in_range(n2, l, r)){
                cnt += 2;
                n1 = r;
                n2 = r-1;
            }
            else if(n_in_range(n1, l, r) && !n_in_range(n2, l, r)){
                cnt++;
                if(n1 != r) n2 = r;
                else n2 = r-1;
            }
            else if(!n_in_range(n1, l, r) && n_in_range(n2, l, r)){
                cnt++;
                if(n2 != r) n1 = r;
                else n1 = r-1;
            }
        }

        return cnt;
    }
};