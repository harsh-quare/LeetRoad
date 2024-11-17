class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> p1(n, 0), p2(n, 0);
        p1[0] = nums[0];
        p2[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            p1[i] = p1[i-1] + nums[i];
        }
        for(int i = n-2; i >= 0; i--){
            p2[i] = p2[i+1] + nums[i];
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            cout << nums[i] << " " << p1[i] << " " << p2[i] << endl;
            if(nums[i] == 0){
                if(abs(p1[i] - p2[i]) == 1) cnt++;
                if(abs(p1[i] - p2[i]) == 0) cnt+=2;
            }
        }
        return cnt;
    }
};