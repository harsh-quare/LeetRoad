class Solution {
public:
    bool validCoupon(string& coupon){
        bool valid = true;
        for(char c: coupon){
            if( !(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9') && !(c == '_')) valid = false;
        }

        return valid;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        vector<int> ansIds;
        unordered_set<string> validBusiness = {"electronics", "grocery", "pharmacy", "restaurant"};

        for(int i = 0; i < n; i++){
            string couponCode = code[i];
            string bsnsLine = businessLine[i];
            bool active = isActive[i];

            if(active == false || couponCode.empty() || !validCoupon(couponCode) || !validBusiness.count(bsnsLine)) continue;

            ansIds.push_back(i);
        }

        sort(ansIds.begin(), ansIds.end(), [&](int id1, int id2){
            if(businessLine[id1] != businessLine[id2]){
                return businessLine[id1] < businessLine[id2];
            }
            else return code[id1] < code[id2];
        });

        vector<string> ans;

        for(int i : ansIds){
            ans.push_back(code[i]);
        }

        return ans;
    }
};