class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    int d1 = (arr[i]-arr[j] >= 0) ? arr[i]-arr[j] : arr[j]-arr[i];
                    int d2 = (arr[j]-arr[k] >= 0) ? arr[j]-arr[k] : arr[k]-arr[j];
                    int d3 = (arr[i]-arr[k] >= 0) ? arr[i]-arr[k] : arr[k]-arr[i];

                    if(d1 <= a && d2 <= b && d3 <= c) cnt++;
                }
            }
        }

        return cnt;
    }
};