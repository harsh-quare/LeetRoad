class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans;
        vector<int> pref(n, 0), suf(n, 0);

        int cnt = 0;
        int temp = 0;

        for(int i = 0; i < n; i++){
            temp += cnt;
            pref[i] = temp;
            cnt += (boxes[i] - '0');

            // cout << cnt << " " << temp << " " << pref[i] << endl;
        }

        cnt = 0, temp = 0;
        for(int i = n-1; i >= 0; i--){
            temp += cnt;
            suf[i] = temp;
            cnt += (boxes[i] - '0');
        }

        for(int i = 0; i < n; i++){
            if(i == 0) ans.push_back(suf[i]);
            else if(i == n-1) ans.push_back(pref[i]);
            else{
                ans.push_back(pref[i] + suf[i]);
            }
        }

        return ans;
    }
};