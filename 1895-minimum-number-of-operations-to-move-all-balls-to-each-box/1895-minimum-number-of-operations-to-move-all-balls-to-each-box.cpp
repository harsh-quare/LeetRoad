class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans;
        // vector<int> p1(n, 0), p2(n, 0);

        for(int i = 0; i < n; i++){
            int left = 0;
            for(int j = 0; j < i; j++){
                if(boxes[j] == '1'){
                    left += (i-j);
                }
            }

            int right = 0;
            for(int j = i+1; j < n; j++){
                if(boxes[j] == '1'){
                    right += (j-i);
                }
            }

            ans.push_back(left + right);
        }

        return ans;
    }
};