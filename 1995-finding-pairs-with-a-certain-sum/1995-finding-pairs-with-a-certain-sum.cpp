class FindSumPairs {
    vector<int> arr1, arr2;
    unordered_map<int, int> mp2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int &x: nums2) mp2[x]++;
        arr1 = nums1;
        arr2 = nums2;
    }
    
    void add(int index, int val) {
        int curVal = arr2[index];
        mp2[curVal]--;
        if(mp2[curVal] == 0) mp2.erase(curVal);

        arr2[index] += val;
        mp2[arr2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i = 0; i < arr1.size(); i++){
            int rem = tot - arr1[i];
            if(mp2.find(rem) != mp2.end()){
                ans += mp2[rem];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */


 // Acc to problem statement, nums1 hamesha intact rahega. Ham usme koi bhi change/modifications nhi kr rhe h
 // To aisa kro ki nums1 ko static array hi rehne do qki iska size 1000 hi h. And nums2 ka map bana lo, jisse hamara kaam easy ho jayega lookup wala