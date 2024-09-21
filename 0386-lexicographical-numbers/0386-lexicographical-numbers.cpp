class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int val = 1; //first level would be 1,2,3,...,9
        for(int i = 0; i < n; i++){
            ans[i] = val;
            if(val*10 > n){  //agar next level pe jaana possible nahi h
            //come back to previous level, because we can't go deeper
                if(val == n){
                    //If current val is equal to 'n', backtrack by dividing by 10, bcz there are no more numbers further to explore
                    val = val/10;
                }
                val++; //moving to next number

                //if the number ends with zero(e.g., 10, 100), keep dividing until, we get rid of the trailing zeros
                while(val%10 == 0) val = val/10;
            }
            //agar next level pe jaa skte h through this val node, means 1 ke child subtree me: 
            //10,100,1000 everyone starting with 1, to try kr lo vaha jaane ka
            else val = val*10;
        }

        return ans;
    }
};
//The first level would look like: 1,2,3,...,9
//Each of them would have 10 children: 1*10+(0,1,2...9); 2*10+(0,1,2...9), and so on: 2nd level
//3rd level: 10 ke 10 child: [100,109]; 11 ke 10 child: [110,119], and so on..