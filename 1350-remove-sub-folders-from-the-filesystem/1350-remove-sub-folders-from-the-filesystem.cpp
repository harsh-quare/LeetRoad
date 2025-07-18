class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        sort(folder.begin(), folder.end());
        vector<string> ans = {folder[0]};

        string prev = folder[0];
        for(int i = 1; i < n; i++){
            string cur = folder[i];

            //If s starts(means, at index-0) with prev + '/', it means that s is a subfolder of prev, so we skip adding s to ans. And if it's not at index-0, means this is not a subfolder of 'prev', so add this new folder to the answer string
            if(cur.find(prev + '/') != 0){
                ans.push_back(cur);
                prev = cur;
            }
        }
        return ans;
    }
};