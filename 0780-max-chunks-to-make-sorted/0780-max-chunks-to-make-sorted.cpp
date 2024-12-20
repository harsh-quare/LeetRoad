class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //For every index, we are checking that if we make a pertition at that index, will it be valid chunk or not??
        //SO, we need a condition to check the validity. 
        //The condition if we observe the proble carefully will be:
        //The maxVal from prefix(0...i) and the minVal from suffix(i+1,...n-1) 
        // (maxPrefVal < minSufVal) => valid partition, increase chunk count

        int chunks = 0;
        int n = arr.size();

        vector<int> prefMax(n);
        prefMax[0] = arr[0];
        vector<int> sufMin(n);
        sufMin[n-1] = arr[n-1];

        for(int i = 0; i < n; i++){
            if(i != 0){
                prefMax[i] = max(prefMax[i-1], arr[i]);
                sufMin[n-i-1] = min(sufMin[n-i], arr[n-i-1]);
            }
        }

        for(int i = 0; i < n; i++){
            int pahleKaMax = (i > 0) ? prefMax[i-1] : -1;
            int aageKaMin = sufMin[i];

            if(pahleKaMax < aageKaMin){
                chunks++;
            }
        }

        return chunks;
    }
};