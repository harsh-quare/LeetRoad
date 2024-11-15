class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        //find the jth pointer from right side
        int j = n-1;
        while(j > 0 && arr[j] >= arr[j-1]){
            j--;
        }

        int i = 0;
        int res = j;  //we are removing all the elements left to index j, bcz index j to n-1 are sorted(this is the max answer possible)

        //step-2: start finding correct i and j and find deleted elements = j-i-1
        while(i < j && (i==0 || arr[i] >= arr[i-1])){
            while(j < n && arr[i] > arr[j]){
                j++;
            }

            //we have found correct jth element such that arr[i] <= arr[j]
            res =min(res, j-i-1);
            i++;
        }

        return res;
    }
};