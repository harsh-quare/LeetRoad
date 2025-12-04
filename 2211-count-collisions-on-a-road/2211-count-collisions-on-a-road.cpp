class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int cols = 0;

        stack<char> st;
        st.push(directions[0]);
        for(int i = 1; i < n; i++){
            if(st.top() == 'R' && (directions[i] == 'L' || directions[i] == 'S')){
                cols += 1;
                cols += (directions[i] == 'L');
                directions[i] = 'S';  // collision done
                st.pop();

                while(!st.empty() && st.top() == 'R'){  // all the consecutive 'R's at top of stack now has an 'S' to collide to
                    cols += 1;
                    st.pop();
                }
            }
            else if(st.top() == 'S' && directions[i] == 'L'){
                cols += 1;
                directions[i] = 'S';
                st.pop();
            }

            st.push(directions[i]);
        }

        return cols;
    }
};