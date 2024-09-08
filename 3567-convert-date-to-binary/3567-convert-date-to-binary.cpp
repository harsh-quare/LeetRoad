class Solution {
public:
    string ans;
    void toBinary(int n){
        while(n){
            if(n & 1){
                ans = "1" + ans;
            }
            else{
                ans = "0" + ans;
            }
            n >>= 1;  //or n/=2
        }
    }
    string convertDateToBinary(string date) {
        int year= stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        toBinary(day);
        ans = "-" + ans;

        toBinary(month);
        ans = "-" + ans;
        
        toBinary(year);
        
        return ans;
    }
};