class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int right = 0, left = 0;
        int ans = 0;

        while(left < arr.size()){
            right= max(right, arr[left]);

            if(right == left){
                right++;
                ans++;
            }
            left++;
        }

        return ans;
    }
};