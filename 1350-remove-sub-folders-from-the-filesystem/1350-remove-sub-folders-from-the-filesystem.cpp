class Solution {
public:
    bool isSubFolder(string& curFolder, string& subFolder){
        // first verify if the subFolder matches till the length of curFolder
        if(curFolder.length() > subFolder.length()) return false;
        for(int i = 0; i < curFolder.size(); i++){
            if(curFolder[i] != subFolder[i]) return false;
        }

        // now, if both of them matches till the length of curFolder, means the subFolder can actually be the sub-folder of curFolder
        // But as a last step, ensure that, the next character in subFolder is '/', bcz if it's not, then it cannot be the sub-folder => ex. "/a/b/c","/a/b/ca"
        if(subFolder[curFolder.length()] != '/') return false;
        
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        vector<string> ans;

        sort(folder.begin(), folder.end());
        int i = 0;
        while(i < n){
            int j = i+1;
            string curFolder = folder[i];
            ans.push_back(curFolder);
            while(j < n && isSubFolder(curFolder, folder[j])){
                j++;
            }
            i = j;
        }
        
        return ans;
    }
};