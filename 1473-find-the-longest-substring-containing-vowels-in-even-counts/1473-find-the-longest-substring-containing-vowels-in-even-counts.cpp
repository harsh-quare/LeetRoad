class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> firstOcc;  
        //firstOcc of the string, bcz we want the max length, so we would be taking the current index - firstOcc index of the string
        //if a string 01000 is already occured previously, means we encountered the vowels even number of times between current index and that prev occ index, that's whay its valid to update the maxLen
        int mask = 0; //00000
        firstOcc[mask] = -1;
        int maxLen = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a'){
                mask = mask ^ (1 << 0);  //uoiea: a is at 0th bit of mask
            }
            else if(s[i] == 'e'){
                mask = mask ^ (1 << 1);
            }
            else if(s[i] == 'i'){
                mask = mask ^ (1 << 2);
            }
            else if(s[i] == 'o'){
                mask = mask ^ (1 << 3);
            }
            else if(s[i] == 'u'){
                mask = mask ^ (1 << 4);
            }

            if(firstOcc.find(mask) != firstOcc.end()){
                maxLen = max(maxLen, i-firstOcc[mask]);
            }
            else{
                //if encountered for the first time, save it as firstOcc
                firstOcc[mask] = i; 
            }
        }

        return maxLen;
    }
};