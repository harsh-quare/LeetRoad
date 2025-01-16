class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // if both even length array
        // [1,2,3,4] [5,6] => 1^5 1^6 2^5 2^6 3^5 3^6 4^5 4^6 => every number from both arrays is occuring even number of times
        // They will cancel each other and answer will be zero
        if(n1 % 2 == 0 && n2 % 2 == 0) return 0;


        int xor1 = 0;
        for(int i = 0; i < n1; i++){
            xor1 ^= nums1[i];
        }
        int xor2 = 0;
        for(int i = 0; i < n2; i++){
            xor2 ^= nums2[i];
        }

        // if both odd length array
        // [1,2,3] [4,5,6] => 1^4 1^5 1^6 2^4 2^5 2^6 3^4 3^5 3^6 => every number from both arrays is occuring odd number of times
        // even number of times they will cancel each other and one occ of each will remain => Xor(nums1) ^ Xor(nums2)
        if(n1 % 2 != 0 && n2 % 2 != 0) return xor1 ^ xor2;



        // if one is even length and another is odd length array
        // [1,2,3] [4,5,6,7] => 1^4 1^5 1^6 1^7 2^4 2^5 2^6 2^7 3^4 3^5 3^6 3^7 => odd length array elements gets repeated even times
        // and even length array elemnts gets repeated odd number of times
        // odd length array elements will cancel out each other
        // even length array elements's one occurence will remain
        if(n1 % 2 != 0) return xor2;
        else return xor1;
        
    }
};