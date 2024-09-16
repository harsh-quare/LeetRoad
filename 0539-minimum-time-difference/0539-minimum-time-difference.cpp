class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> help;
        for(int i = 0; i < n; i++){
            string time = timePoints[i];
            int hh = stoi(time.substr(0, 2));
            int mm = stoi(time.substr(3, 2));
            int t = hh*60 + mm;
            help.push_back(t);
        }

        sort(help.begin(), help.end());
        int mini = INT_MAX;
        
        int sz = help.size();
        for(int i = 0; i < sz-1; i++){
           mini = min(mini, help[i+1]-help[i]);
        }

        mini = min(mini, 1440 - help[sz-1] + help[0]);

        return mini;
    }
};