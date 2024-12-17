class NumArray {
private:
    int n;
    vector<int> seg;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        buildSeg(0, 0, n-1, nums);
    }
    
    int sumRange(int left, int right) {
        return rangeSum(0, 0, n-1, left, right);
    }

    //segment tree
    void buildSeg(int i, int l, int r, vector<int>& nums){
        if(l == r){
            seg[i] = nums[l];
            return ;
        }

        int mid = (l + r)/2;

        buildSeg(2*i+1, l, mid, nums);
        buildSeg(2*i+2, mid+1, r, nums);

        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int rangeSum(int i, int l, int r, int left, int right){
        //out of bound entirely
        if(l > right || r < left){
            return 0;
        }

        if(l >= left && r <= right){
            return seg[i];
        }

        int mid = (l+r)/2;

        return rangeSum(2*i+1, l, mid, left, right) + rangeSum(2*i+2, mid+1, r, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */