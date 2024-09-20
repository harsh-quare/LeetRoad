class Solution {
public:
    string shortestPalindrome(string s) {
        //First, find the Longest Palindromic substring present as the preffix part
        //because we want to add characters in front, means the palindromic prefix part is okay but the problematic part is
        //the suffix part which is not palindromic and we need to copy that suffix in front as reverse so that it becomes pal.

        string r = s;
        reverse(r.begin(), r.end());
        
        //check which prefix is palindromic by comparing prefix of original string to suffix of reversed string
        for(int i = 0; i < s.size(); i++){
            //memcmp funcn takes 3 parameters: pointer1, pointer2, length(in which comparison is to be made bw ptr1 and ptr2)
            //s.c_str(): string s is converted into c-type string(character array) and pointer points to the starting index
            //r.c_str(): string r is converted into c-type string(character array) and pointer points to the starting index
            //length of the part in which the pointers will be comparing the characters in the character arrays
            //memcmp returns 0 if the strings are matched
            if(memcmp(s.c_str() + 0, r.c_str() + i, s.size()-i) == 0){
                //we needed the prefix of s string, so start from 0 index, and length is n-i
                //and the suffix of r string, so start from i index and length is n-i
                return r.substr(0, i) + s;  //suffix of reversed is palindromic so the problematic part is prefix of rev str
                //so copy that in front of the original string and it will be palindromic now
            }
        }

        return r + s;  //if there was no palindromic prefix, means no part matches, every character needs to be copied
    }
};