class Solution {
public:
    bool canChange(string start, string target) {
        //sequence to hamesha same rahega
        int n = start.size(), m = target.size();
        if(n != m) return false;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(start[i] == '_' && target[j] != '_'){
                i++;
            }
            else if(start[i] != '_' && target[j] == '_'){
                j++;
            }
            else{
                if(start[i] != target[j]) return false;
                else{
                    if(start[i] == 'L' && j > i) return false;  //agar dono character same('L') h, but target me L start wale 'L' ki position se aage h, to ham to vaha 'L' ko leke ja hi nhi skte, qki 'L' only left me move krta h, isliye false
                    else if(start[i] == 'R' && i > j) return false; //agar dono character same('R') h, but target me R, start wale 'R' ki position se peeche h, to ham to vaha 'R' ko leke ja hi nhi skte, qki 'R' only right me move krta h, 
                    // example: start = "_LL__R__R_" ; target = "L___L___RR"
                    i++;
                    j++;
                }
            }
        }

        //agar start ke remaining part me koi whitespace ke alava character reh gya, to woh to kabhi kisi se match ho hi nhi skta
        while(i < n){
            if(start[i] != '_') return false;
            i++;
        }

        while (j < m) {
            if (target[j] != '_') return false;
            j++;
        }

        if(j == m) return true;  //agar target me last tak pura match ho gya h, tabhi valid h: refer dry run example-3
        return false;
    }
};