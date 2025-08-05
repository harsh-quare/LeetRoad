class Solution {
public:
    void buildSeg(vector<int>& baskets, vector<int>& seg, int low, int hi, int i){
        if(low == hi){
            seg[i] = baskets[low];
            return ;
        }

        int mid = (low + hi) / 2;

        buildSeg(baskets, seg, low, mid, 2*i+1);
        buildSeg(baskets, seg, mid+1, hi, 2*i+2);

        seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
    }

    bool isInRange(vector<int>& seg, int goal, int low, int hi, int i){
        if(low == hi){
            if(seg[i] >= goal){
                seg[i] = 0;  // mark used
                return true;
            }
            else{
                return false;
            }
        }

        if(seg[i] >= goal){
            int mid = (low + hi) / 2;
            bool f1 = isInRange(seg, goal, low, mid, 2*i + 1);
            if(!f1) f1 |= isInRange(seg, goal, mid + 1, hi, 2*i + 2);

            seg[i] = max(seg[2*i + 1], seg[2*i + 2]);
            return f1;
        }
        else return false;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        vector<int> seg(4*n, 0);
        buildSeg(baskets, seg, 0, n-1, 0);

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!isInRange(seg, fruits[i], 0, n-1, 0)) cnt++;
        }

        return cnt;
    }
};