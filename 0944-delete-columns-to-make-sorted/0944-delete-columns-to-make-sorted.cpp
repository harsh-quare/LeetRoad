class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int strSize = strs.size();
        int columns = strs[0].size();

        int invalidColumns = 0;

        for(int curColIdx = 0; curColIdx < columns; curColIdx++){
            for(int curRowIdx = 1; curRowIdx < strSize; curRowIdx++){
                char curChar = strs[curRowIdx][curColIdx];
                char prevChar = strs[curRowIdx-1][curColIdx];

                if(curChar < prevChar) {
                    invalidColumns++;
                    break;
                }
            }
        }

        return invalidColumns;
    }
};