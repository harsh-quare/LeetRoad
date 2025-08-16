class Solution {
public:
    int maximum69Number (int num) {
        vector<int> n;
        while(num > 0){
            n.push_back(num % 10);
            num = num / 10;
        }

        for(int i = n.size() - 1; i >= 0; i--){
            if (n[i] == 6) {
                n[i] = 9;
                break;
            }
        }

        int newNum = 0;
        for(int i = n.size() - 1; i >= 0; i--){
            newNum *= 10;
            newNum += n[i];
        }
        return newNum;
    }
};