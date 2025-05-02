class Solution {
public:
    string pushDominoes(string d) {
        d = 'L' + d + 'R';  // to tackle the ending dots, as adding these will not trigger their movement
        string ans;

        int i = 0;
        for(int j = 1; j < d.size(); j++){
            if(d[j] == '.'){
                continue;
            }

            int dots = j - i - 1;
            if(i > 0){
                ans += d[i];  // j character add kr diya, ye check lagaya qki i = 0 ka matlab extra add kiya hua 'L'
            }

            if(d[i] == d[j]){  // both are "L", or 'R'
                ans += string(dots, d[i]);  // L...L => LLLLL and R...R => RRRRR
            }
            else if(d[i] == 'L' && d[j] == 'R'){  // 'L...R'  => 'L...R'
                ans += string(dots, '.');
            }
            else{  // 'R...L'  =>  'RR.LL'
                ans += string(dots/2, 'R') + string(dots % 2, '.') + string(dots/2, 'L');
            }

            i = j;
        }

        return ans;
    }
};