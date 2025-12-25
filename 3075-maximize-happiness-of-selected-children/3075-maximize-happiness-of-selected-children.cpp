class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());
        long long total = 0;
        int cnt = 0;
        for(int i = n-1; i >= n-k; i--){
            int newVal = max(0, happiness[i] - cnt);
            if(newVal == 0) break;   // from now onwards, you will only get 0s

            cnt++;
            total += newVal;
        }

        return total;
    }
};

// 1st child comes with hit full capacity of happiness => the max guy of the array
// from 2nd onwards => all of them will have reduced their happiness by 1 on each selection => 1,2,3,4...k-1
// why k-1 => we select k children, and 1st of those is coming with original value(no reduction)
// for next k-1 children => 1 => -1, 2 => -2, ... k-1
// so the answer becomes => sum of top k values - (k-1)*(k) / 2;  => if no value go below 0
// else keep decrementing at each step and take the max(0, newVal);