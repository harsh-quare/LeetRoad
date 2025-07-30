class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int cntA = 0;
        int cntB = 0;

        int lenA = 0, lenB = 0;
        for(int i = 0; i < n; i++){
            if(colors[i] == 'A'){
                // B khatam ho gya, cntB update kr do
                if(lenB > 2) {
                    cntB += (lenB - 2);
                }
                lenB = 0;  // reset B len

                lenA++;
            }
            else{
                // A khatam ho gya, cntA update kr do
                if(lenA > 2){
                    cntA += (lenA - 2);
                }
                lenA = 0;  // reset A len

                lenB++;
            }
        }

        // Last continuous string
        if(lenB > 2){
            cntB += (lenB - 2);
        }
        if(lenA > 2){
            cntA += (lenA - 2);
        }

        cout << cntA << ", " << cntB << endl;

        if(cntA > cntB) return true;
        else return false;  //  if(cntA <= cntB) 
        
    }
};