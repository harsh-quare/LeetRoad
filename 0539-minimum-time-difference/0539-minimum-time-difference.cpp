class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //#1. Brute force
        int n = timePoints.size();
        vector<int> help;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            string time = timePoints[i];
            int hh = stoi(time.substr(0, 2));
            int mm = stoi(time.substr(3, 2));
            int t = hh*60 + mm;
            // cout << t1 << endl;
            help.push_back(t);
        }

        sort(help.begin(), help.end());
        
        int sz = help.size();
        for(int i = 0; i < sz-1; i++){
           mini = min(mini, help[i+1]-help[i]);

            if(mini == 0) return 0;
        }

        mini = min(mini, 24*60 - help[sz-1] + help[0]);

        return mini;
    }
};