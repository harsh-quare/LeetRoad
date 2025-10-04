class Solution {
public:
    bool canChoose(vector<int>& price, int k, int mid){
        int prevChosen = price[0];  // choose the smallest to maximize the diff
        k-=1;  // 1 is chosen
        for(int i = 1; i < price.size(); i++){
            if(price[i] >= prevChosen + mid){
                k--;
                prevChosen = price[i];
            }
        }

        return (k <= 0);
    }
    int maximumTastiness(vector<int>& price, int k) {
        // maximize the minimum
        // we can try to binary search on the difference
        int n = price.size();
        sort(price.begin(), price.end());
        for(int x: price){
            cout << x << ", ";
        }
        cout << endl;
        int l = 0;
        int r = price[n-1] - price[0];
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            // cout << mid << endl;

            if(canChoose(price, k, mid)){   // Can I choose k elements from price with a difference of >= 'mid'
                // cout << mid << endl;
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return ans;
    }
};