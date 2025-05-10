class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        long long s1 = 0, s2 = 0;
        int z1 = 0, z2 = 0;

        for(int i = 0; i < n1; i++){
            s1 += nums1[i];
            z1 += (nums1[i] == 0);
        }
        cout << s1 << ", " << z1 << endl;
        for(int i = 0; i < n2; i++){
            s2 += nums2[i];
            z2 += (nums2[i] == 0);
        }
        cout << s2 << ", " << z2 << endl;

        if(z1 > 0 && z2 > 0){
            return max(s1 + z1, s2 + z2);
        }
        else if(z1 == 0 && z2 == 0){
            if(s1 == s2) return s1;
            else return -1;
        }

        if(z1 == 0 && s1 >= s2+z2) return s1;
        if(z2 == 0 && s2 >= s1+z1) return s2;

        return -1;
    }
};