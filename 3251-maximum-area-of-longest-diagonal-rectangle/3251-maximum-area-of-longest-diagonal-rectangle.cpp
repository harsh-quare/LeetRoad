class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double mxDiag = 0;
        int mxArea = 0;

        for(auto& it: dimensions){
            int l = it[0];
            int w = it[1];

            double diag = sqrt(pow(l,2) + pow(w,2));
            cout << diag << endl;

            if(diag > mxDiag){
                mxDiag = diag;
                mxArea = l*w;
            }
            else if(diag == mxDiag){
                if(l*w > mxArea){
                    mxArea = l*w;
                }
            }
        }
        
        return mxArea;
    }
};