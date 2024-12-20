class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        //The info that is provided in the problem statement, that all the numbers are between 0 to n-1, its very imp
        //because if are trying to divide the array into some chunks so that after sorting them individually and combinint them, it will result in a sorted array
        //and we already know how the sorted array looks. 0,1,2,3,4,...n-1
        //so we already know the positions and their respective number that should be there
        //now we can simply compare the cummulative sums till each index, if that becomes equal, i.e. that chunk is valid

        int chunks = 0;
        int cumSum = 0;
        int orgSum = 0;
        for(int i = 0; i < arr.size(); i++){
            cumSum += arr[i];
            orgSum += i;

            if(cumSum == orgSum){
                //mtlb iss index tk arr ki values same h desired array jesi hi, but unsorted ho skti h. But qki cumSUm h, to ham iss part ka sum le rhe h to woh equal aa rha h
                chunks++;
            }
        }

        return chunks;
    }
};