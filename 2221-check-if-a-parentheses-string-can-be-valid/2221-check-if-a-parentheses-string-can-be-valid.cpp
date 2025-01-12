class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2 != 0) return false;  //odd length wali string to kabhi valid par. bana hi nhi skte
        
        int openCnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(locked[i] == '0' || s[i] == '(') openCnt++;
            else openCnt--;  //closing-locked milega to remove kr do open wale ek bnde ko

            if(openCnt < 0){
                return false; // agar kisi bhi moment pe jyada closing locked mil jate h, jitne hamare paas uske left me balancing open nhi h, to false return kr do
            }
        }

        openCnt = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(locked[i] == '0' || s[i] == ')') openCnt++;
            else openCnt--;

            if(openCnt < 0) return false;
        }

        return true;
    }
};