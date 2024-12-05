class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size(), m = result.size();

        //Length mismatch: Immediate failure
        if (n != m) return false;

        int i = 0, j = 0;
        while(i < n && j < m){
            //Skip 'X's in both strings
            while(i < n && start[i] == 'X') i++;
            while(j < m && result[j] == 'X') j++;

            //If one reaches the end and the other does not
            if(i == n || j == m) break;

            //If the characters at i and j are not the same
            if(start[i] != result[j]) return false;

            //Check movement constraints
            if(start[i] == 'L' && j > i) return false; // 'L' cannot move right
            if(start[i] == 'R' && i > j) return false; // 'R' cannot move left

            i++;
            j++;
        }

        //Check if there are any non-'X' characters left in start
        while(i < n){
            if(start[i] != 'X') return false;
            i++;
        }

        //Check if there are any non-'X' characters left in result
        while(j < m){
            if(result[j] != 'X') return false;
            j++;
        }

        return true;
    }
};
// similar to problem #2337: move pieces to obtain a string
// we move towards left if we have any 'L'
// we move toward right if we have any 'R'
// 'X' are treated as whitespaces, we can move on that