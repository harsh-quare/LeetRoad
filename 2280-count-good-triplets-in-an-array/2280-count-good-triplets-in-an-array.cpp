class Solution {
public:
    vector<long long> segTree;

    void updateSegTree(long long st_idx, long long st, long long end, long long& query_idx){
        if(end < query_idx || st > query_idx){
            // case-1: no overlap
            return ;
        }

        if(st == end){
            //case-2: total overlap
            segTree[st_idx]++;
            return ;
        }

        // case-3: partial overlap
        long long mid = st + (end - st) / 2;
        updateSegTree(2*st_idx, st, mid, query_idx);
        updateSegTree(2*st_idx + 1, mid + 1, end, query_idx);

        segTree[st_idx] = segTree[2*st_idx] + segTree[2*st_idx + 1];
    }

    int rangeSumQuery(long long st_idx, long long st, long long end, long long qs, long long qe){
        if(qs > end || qe < st) return 0;  // no overlap
        if(st >= qs && end <= qe) return segTree[st_idx];  // total overlap

        // partial overlap
        long long mid = st + (end - st) / 2;
        long long left_sum = rangeSumQuery(2*st_idx, st, mid, qs, qe);
        long long right_sum = rangeSumQuery(2*st_idx + 1, mid + 1, end, qs, qe);

        return left_sum + right_sum;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        // We use segment tree to efficiently find number of common elements in left side and right side of a current index value
        // step-1: defining segment tree and saving val->idx for elements in nums2
        long long n = nums1.size();
        segTree = vector<long long>(4*n+1, 0);

        unordered_map<long long, long long> nums2_val_idx;
        for(long long i = 0; i < n; i++){
            nums2_val_idx[nums2[i]] = i;
        }

        // step-2: pushing the leftmost item in segment tree and process all items from idx 1
        updateSegTree(1, 0, n-1, nums2_val_idx[nums1[0]]);

        long long cnt_good_tripls = 0;
        for(long long i = 1; i < n-1; i++){
            // considering i as the middle element in triplet
            long long nums2_idx = nums2_val_idx[nums1[i]];
            long long common_left_items = rangeSumQuery(1, 0, n-1, 0, nums2_idx);
            long long uncommon_left_items = (i - common_left_items);  // total_in_left - common
            long long common_right_items = (n - nums2_idx - 1) - uncommon_left_items;  // total_in_right - uncommon_from_left => bcz the items which are uncommon in left part of nums2, will be definately appearing in right part, and there also they will be uncommon
            cnt_good_tripls += common_left_items * common_right_items;

            updateSegTree(1, 0, n-1, nums2_idx);
        }

        return cnt_good_tripls;
    }
};