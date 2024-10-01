class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto x: arr){
            int rem = ((x % k) + k) % k;
            mp[rem]++;
        }

        //trying every remainder
        for(int i = 0; i <= k/2; i++){
            if(i == 0){
                if(mp[i] % 2 != 0) return false;
            }
            else if(k % 2 == 0 && i == k-i){ 
                //means i = k/2 par, bhi hame jo desired mod chahiye woh k/2 wale pe hi milega, agar k even h to
                if(mp[i] % 2 != 0) return false;
            }
            else{
                if(mp[i] != mp[k-i]) return false;
            }
        }

        return true;
    }
};