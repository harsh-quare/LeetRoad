class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int last = -1, secondLast = -1;
        int lastCnt = 0;
        int curWindow = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            int f = fruits[i];

            if(f == last || f == secondLast){
                curWindow++;
            }
            else{
                curWindow = lastCnt + 1;
            }

            if(f == last){
                lastCnt++;
            }
            else{
                lastCnt = 1;
                secondLast = last;
                last = f;
            }

            ans = max(ans, curWindow);
        }

        return ans;
    }
};