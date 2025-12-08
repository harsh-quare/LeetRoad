class Solution {
public:
    int countTriples(int n) {
        // Method-2 => Better, O(n^2), Try all pairs and check if the sqr sum is <= n or not

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int a = pow(i, 2);
                int b = pow(j, 2);

                double c = sqrt(a + b);

                if(c <= n && (int)c*c == a + b) cnt++;
            }
        }

        return cnt;
    }
};