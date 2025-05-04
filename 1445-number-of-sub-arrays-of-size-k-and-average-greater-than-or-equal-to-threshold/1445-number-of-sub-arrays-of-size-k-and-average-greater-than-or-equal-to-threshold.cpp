class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int cnt = 0;
        int curSum = 0;

        // process first window of k size
        for(int i = 0; i < k; i++){
            curSum += arr[i];
        }

        if(curSum >= threshold*k) cnt++;

        // process remaining windows
        int i = k;
        while(i < n){
            curSum += arr[i];
            curSum -= arr[i-k];

            if(curSum >= threshold*k) cnt++;

            i++;
        }

        return cnt;
    }
};