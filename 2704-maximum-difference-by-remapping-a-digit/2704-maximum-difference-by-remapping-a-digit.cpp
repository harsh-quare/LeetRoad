class Solution {
public:
    int minMaxDifference(int num) {
        // to make it maximum, go from left to right, and the first guy not equal to 9, becomes 9
        // to make it minimum, change the most significant digit to 0
        string s = to_string(num);
        char remap_for_max_dig = ' ', remap_for_min_dig = s[0];
        int i = 0;
        int n = s.size();
        while(i < n && s[i] == '9'){
            i++;
        }

        int maxi = 0, mini = 0;
        if(i == n){
            maxi = stoi(s);
        }
        else{
            remap_for_max_dig = s[i];
            for(int j = n-1; j >= 0; j--){
                if(s[j] == remap_for_max_dig) maxi = maxi + 9*pow(10,n-j-1);
                else maxi = maxi + (s[j]-'0')*pow(10, n-j-1);
            }
        }

        for(int j = s.size()-1; j >= 0; j--){
            if(s[j] == remap_for_min_dig){
                s[j] = '0';
            }
        }

        mini = stoi(s);

        // cout << maxi << ", " << mini << endl;

        return maxi-mini;
    }
};