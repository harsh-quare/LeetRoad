class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

        long long ans1 = (long long)cost1*need1 + (long long)cost2*need2;

        long long ans2 = (long long)costBoth*(need1 < need2 ? need1 : need2) + (need1 < need2 ? 1LL*(need2-need1)*cost2 : 1LL*(need1-need2)*cost1);

        long long ans3 = (long long)costBoth * max(need1, need2);

        return min(ans1, min(ans2, ans3));
    }
}; 