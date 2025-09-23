class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0; 
        int j = 0;

        while(i < version1.size() || j < version2.size()){
            int val1 = 0;
            while(i < version1.size() && version1[i] != '.'){
                val1 = val1*10 + (version1[i]-'0');
                i++;
            }
            i++;

            int val2 = 0;
            while(j < version2.size() && version2[j] != '.'){
                val2 = val2*10 + (version2[j]-'0');
                j++;
            }
            j++;

            // processed both versions till '.'
            if(val1 < val2) return -1;
            else if(val1 > val2) return 1;
        }

        return 0;
    }
};