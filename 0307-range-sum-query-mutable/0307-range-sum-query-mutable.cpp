class NumArray {
    void buildSegTree(int i, int l, int r, vector<int>& segTree, vector<int>& nums){
        if(l == r){
            segTree[i] = nums[l];
            return ;
        }

        int mid = l + (r - l) / 2;

        buildSegTree(2*i + 1, l, mid, segTree, nums);
        buildSegTree(2*i + 2, mid + 1, r, segTree, nums);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void updateSegTree(int idx, int val, int i, int l, int r, vector<int>& segTree){
        if(l == r){
            segTree[i] = val;
            return ;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid){
            updateSegTree(idx, val, 2*i+1, l, mid, segTree);
        }
        else{
            updateSegTree(idx, val, 2*i+2, mid+1, r, segTree);
        }

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int findSum(int left, int right, int i, int l, int r, vector<int>& segTree){
        if(l > right || r < left) return 0;  // no overlap

        if(l >= left && r <= right) return segTree[i];  // completely inside the range

        // partially
        int mid = l + (r - l) / 2;
        return findSum(left, right, 2*i+1, l, mid, segTree) + findSum(left, right, 2*i+2, mid+1, r, segTree);
    }
public:
    int n;
    vector<int> segTree;
    vector<int> lazy;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n+1, 0);
        lazy.resize(4*n+1, 0);

        buildSegTree(0, 0, n-1, segTree, nums);
    }
    
    void update(int index, int val) {
        // point update
        updateSegTree(index, val, 0, 0, n-1, segTree);
    }
    
    int sumRange(int left, int right) {
        return findSum(left, right, 0, 0, n-1, segTree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */