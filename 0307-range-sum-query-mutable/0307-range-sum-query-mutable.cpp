class NumArray {
private:
    int n;
    vector<int> nums;
    vector<int> segTree;
public:
    NumArray(vector<int>& nums) {
        //build segment tree
        this->nums = nums;
        n = nums.size();
        segTree.resize(4*n);
        buildTree(0, 0, n-1, this->nums);
    }
    
    void update(int index, int val) {
        updateQuery(index, val, 0, 0, n-1, this->nums);
    }
    
    int sumRange(int left, int right) {
        return rangeSum(left, right, 0, 0, n-1);
    }




    //for segment tree
    void buildTree(int i, int l, int r, vector<int>& nums){
        //base case
        if(l == r){
            segTree[i] = nums[l];
            return ;
        }

        int mid = (l + r) / 2;

        buildTree(2*i + 1, l, mid, nums);
        buildTree(2*i + 2, mid + 1, r, nums);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }


    void updateQuery(int idx, int val, int i, int l, int r, vector<int>& nums){
        if(l == r){
            segTree[i] = val;
            return;
        }
        
        int mid = (l + r) / 2;

        if(idx <= mid){
            updateQuery(idx, val, 2*i+1, l, mid, nums);
        }
        else{
            updateQuery(idx, val, 2*i+2, mid + 1, r, nums);
        }

        //update node values after query updation and coming back
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    int rangeSum(int left, int right, int i, int l, int r){
        
        //entirely out of bound query
        if(l > right || r < left){
            return 0;
        }

        //entirely inside bounds
        if(l >= left && r <= right){
            return segTree[i];
        }

        int mid = (l+r)/2;

        //else: overlapping
        return rangeSum(left, right, 2*i+1, l, mid) + rangeSum(left, right, 2*i+2, mid+1, r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */