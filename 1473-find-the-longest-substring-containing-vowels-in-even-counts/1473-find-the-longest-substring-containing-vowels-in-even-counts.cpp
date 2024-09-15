class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> cnt(5, 0);  //a,e,i,o,u: 0,0,0,0,0
        unordered_map<string, int> firstOcc;  
        //firstOcc of the string, bcz we want the max length, so we would be taking the current index - firstOcc index of the string
        //if a string 01000 is already occured previously, means we encountered the vowels even number of times between current index and that prev occ index, that's whay its valid to update the maxLen
        firstOcc["00000"] = -1; //initially we had the string as "00000"
        int maxLen = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a'){
                cnt[0] = cnt[0]^1;//if it has occured even number of times, it will be zero or else it will be 1
            }
            else if(s[i] == 'e'){
                cnt[1] = cnt[1]^1;
            }
            else if(s[i] == 'i'){
                cnt[2] = cnt[2]^1;
            }
            else if(s[i] == 'o'){
                cnt[3] = cnt[3]^1;
            }
            else if(s[i] == 'u'){
                cnt[4] = cnt[4]^1;
            }

            //Ab string nikal lo and check kr lo map me
            string check = "";
            for(int j = 0; j < 5; j++){
                check += to_string(cnt[j]);
            }

            if(firstOcc.find(check) != firstOcc.end()){
                maxLen = max(maxLen, i-firstOcc[check]);
            }
            else{
                //if encountered for the first time, save it as firstOcc
                firstOcc[check] = i; 
            }
        }

        return maxLen;
    }
};