class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size(), m = target.size();

        //Length mismatch: Immediate failure
        if (n != m) return false;

        int i = 0, j = 0;
        while(i < n && j < m){
            //Skip underscores in both strings
            while(i < n && start[i] == '_') i++;
            while(j < m && target[j] == '_') j++;

            //If one reaches the end and the other does not
            if(i == n || j == m) break;

            //If the characters at i and j are not the same
            if(start[i] != target[j]) return false;

            //Check movement constraints
            if(start[i] == 'L' && j > i) return false; // 'L' cannot move right
            if(start[i] == 'R' && i > j) return false; // 'R' cannot move left

            i++;
            j++;
        }

        //Check if there are any non-'_' characters left in start
        while(i < n){
            if(start[i] != '_') return false;
            i++;
        }

        //Check if there are any non-'_' characters left in target
        while(j < m){
            if(target[j] != '_') return false;
            j++;
        }

        return true;
    }
};
