class Solution {
public:
    void buildSegTree(vector<int>& bs, vector<int>& seg, int lo, int hi, int i){
        if(lo == hi){  // reached leaf node
            seg[i] = bs[lo];
            return ;
        }

        int mid = (lo + hi) / 2;
        // build tree recursively
        buildSegTree(bs, seg, lo, mid, 2*i + 1);
        buildSegTree(bs, seg, mid+1, hi, 2*i + 2);

        seg[i] = max(seg[2*i+1], seg[2*i+2]);  // get the max values from child nodes
    }

    bool isInRange(int tar, vector<int>& seg, int lo, int hi, int i){
        if(lo == hi){
            if(seg[i] >= tar){
                // mark as used
                seg[i] = 0;
                return true;
            }
            else return false;
        }

        if(seg[i] >= tar){
            // go deeper
            int mid = (lo + hi) / 2;
            bool ans1 = isInRange(tar, seg, lo, mid, 2*i+1);  // left subtree
            if(ans1 == false) ans1 |= isInRange(tar, seg, mid+1, hi, 2*i+2);  // right subtree

            seg[i] = max(seg[2*i+1], seg[2*i+2]);   // update the current node value, bcz some nodes might get used, and there values were changed to 0, so there will be difference in parent nodes
            return ans1;
        }
        else return false;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        vector<int> seg(4*n, 0);
        buildSegTree(baskets, seg, 0, n-1, 0);  // array(in which we need to find the maximums to the left), segTree array, low pointer, high pointer, curIndex of segTree

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!isInRange(fruits[i], seg, 0, n-1, 0)){  // find out if there is someone available in segTree for fruits[i]
                cnt++;
            }
        }

        return cnt;
    }
};