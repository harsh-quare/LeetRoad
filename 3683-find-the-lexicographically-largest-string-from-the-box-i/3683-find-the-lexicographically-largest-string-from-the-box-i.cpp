class Solution {
public:
    // string solve(string &s1, string &s2){
    //     int n = s1.size();
    //     for(int i = 0; i < n; i++){
    //         if(s1[i] == s2[i]) continue;
    //         else if(s1[i] > s2[i]) return s1;
    //         else return s2;
    //     }
    //     return s1;  // agar continue krte krte yaha pahuch gye, mtlb dono strings same h, return any of them
    // }
    string answerString(string word, int numFriends) {
        // num-1 friends ko ham single single character de denge, ek jo hoga uski length ho jayegi word.length()-(num-1), and vahi longest string hame mil skti h
        // ab hame lexicographically largest chahiye to, check kr lo har index pe jaake, itni length ki substr bana ke, jaha bhi lexicographically largest mil jaye vahi answer h

        if(numFriends == 1) return word;

        int ansLen = word.size() - (numFriends - 1);
        string ans = "";

        for(int i = 0; i < word.size(); i++){
            string temp = word.substr(i, ansLen);
            // if(ans.empty()) ans = temp;
            // else ans = solve(ans, temp);

            ans = max(ans, temp);
        }

        return ans;
    }
};