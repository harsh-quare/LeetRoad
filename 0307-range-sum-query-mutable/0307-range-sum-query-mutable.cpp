class NumArray {
public:
    int n;
    vector<int> st;
    vector<int> lazy;

    void buildSt(int i, int l, int r, vector<int>& nums){
        //base case
        if(l == r){
            st[i] = nums[l];
            return ;
        }

        int mid = (r+l)/2;

        buildSt(2*i + 1, l, mid, nums);
        buildSt(2*i + 2, mid+1, r, nums);

        st[i] = st[2*i+1] + st[2*i+2];
    }

    void updateQuery(int id, int val, int i, int l, int r){
        if(l == r){
            st[i] = val;
            return ;
        }

        int mid = (r+l)/2;

        if(id <= mid){
            updateQuery(id, val, 2*i+1, l, mid);
        }
        else{
            updateQuery(id, val, 2*i+2, mid+1, r);
        }

        st[i] = st[2*i+1] + st[2*i+2];
    }

    int rangeSum(int start, int end, int i, int l, int r){
        //entirely out of bound
        if(l > end || r < start){
            return 0;
        }

        if(l >= start && r <= end){
            return st[i];
        }

        int mid = (r+l)/2;

        return rangeSum(start, end, 2*i+1, l, mid) + rangeSum(start, end, 2*i+2, mid+1, r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n);
        lazy.resize(4*n, 0);
        buildSt(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateQuery(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return rangeSum(left, right, 0, 0, n-1);
    }

    void updateRange(int start, int end, int val, int i, int l, int r){
        if(lazy[i] != 0){
            st[i] += (r-l+1) * lazy[i];
            if(l != r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }

        if(l > end || r < start || l > r){
            return ;
        }

        if(l >= start && r <= end){
            st[i] += (r-l+1)*val;
            if(l != r){
                lazy[2*i + 1] += val;
                lazy[2*i + 2] += val;
            }

            return ;
        }

        int mid = (l + r)/2;

        updateRange(start, end, val, 2*i+1, l, mid);
        updateRange(start, end, val, 2*i+2, mid+1, r);

        st[i] = st[2*i+1] + st[2*i+2];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */