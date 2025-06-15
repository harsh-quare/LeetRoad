class Solution {
public:
    int maxDiff(int num) {
        // for a => change most significant digit to 9
        // for b => change most significant digit to 1 => not 0, bcz neither a nor b may have any leading zeros, and must not be 0.
        // and there is a slight modification in rule 2, for ex: num = 123456
        // we already have 1 at msd, so we try to change the first guy not equal to 1, to 1
        
        string x = to_string(num);
        string a = x;
        string b = a;

        char msd_a = a[0];
        char msd_b = b[0];
        bool msd_1_in_b = (b[0] == '1');  // agar pehla digit already h, to optimal strategy ye h, ki next significant digit which is not '1', should become '0', bcz that will both make it smaller and there will not be leading zeros now
        bool msd_9_in_a = (a[0] == '9');
        
        for(int i = 0; i < a.size(); i++){
            if(msd_1_in_b == true && b[i] > '1'){   // agar pehla digit 0 h, and first such digit encounter hua, jo 1 ya 1 se chhota nhi h
                msd_b = b[i];
                msd_1_in_b = false;
            }
            if(msd_9_in_a == true && a[i] < '9'){
                msd_a = a[i];
                msd_9_in_a = false;
            }

            if(a[i] == msd_a) a[i] = '9';

            if(b[i] == '0') continue;
            if(b[i] == msd_b && msd_b != x[0]) b[i] = '0';  // to ensure we are not replacing a guy with '0' who is at most significant place
            else if(b[i] == msd_b && msd_b == x[0]) b[i] = '1';  // if the digit is also a msd, so we replace it with 1
        }
        
        cout << stoi(a) << ", " << stoi(b) << endl;

        return stoi(a) - stoi(b);
    }
};