class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> eligibles;  // who needs to learn a new language

        for(auto& f: friendships){
            int u = f[0]-1;
            int v = f[1]-1;

            bool talk = false;
            for(int l1: languages[u]){
                for(int l2: languages[v]){
                    if(l1 == l2){
                        talk = true;
                        break;
                    }
                }
                if(talk == true){
                    break;
                }
            }

            if(!talk){
                eligibles.insert(u);
                eligibles.insert(v);
            }
        }

        int ans = languages.size();  // teach all the people

        for(int lang = 1; lang <= n; lang++){
            int cnt = 0;

            for(int u: eligibles){
                bool speaksLang = false;
                for(int l: languages[u]){
                    if(l == lang){
                        speaksLang = true;
                        break;
                    }
                }
                if(!speaksLang) cnt++;
            }

            ans = min(ans, cnt);
        }

        return ans;
    }
};