class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [&](int a, int b){
            string s1 = to_string(a);
            string s2 = to_string(b);

            if((s1 + s2) > (s2 + s1)){ //"8" + "67" > "67" + "8" => "867" > "678"
                return true;
            }
            return false;
        };

        sort(nums.begin(), nums.end(), cmp);

        //agar sort krne ke baad 0th index pe jo ki sabse badi value store kr rha h, vahi pe 0 pada h, to return 0
        if(nums[0] == 0) return "0";
        
        string ans = "";
        for(int i = 0; i < nums.size(); i++){
            ans += to_string(nums[i]);
        }

        return ans;
    }
};