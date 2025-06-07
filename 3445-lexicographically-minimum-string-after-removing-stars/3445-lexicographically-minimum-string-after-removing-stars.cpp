class Solution {
public:
    #define pci pair<char, int>
    // Method-2: using a struct class function
    struct comp{
        bool operator()(pci a, pci b){
            // first part in ascending, and second part in descending
            // means characters should be in descending => a,b,c
            // and their index in descending means latest first => b,5 ; b,3
            if(a.first > b.first){
                return true;
            }
            else if(a.first == b.first && a.second < b.second){
                return true;
            }

            return false;
        }
    };
    string clearStars(string s) {
        // I need to know about the smallest non-'*' character to the left of each '*' character
        // for that my first thought was to use an extra array, and store minChar to the left of each index, but the problem in that case is that, once the '*' is encountered it will delete the smallestToLeft, but now I don't know who is the second smallest for the next '*', I need to keep track of all the characters in such an order, that the smallest appears on the top, and once removed, second smallest appears right up there => minHeap

        int n = s.size();

        // Method-1: lambda function
        // auto comp = [](pci a, pci b){
        //     if(a.first > b.first){
        //         return true;
        //     }
        //     else if(a.first == b.first && a.second < b.second){
        //         return true;
        //     }

        //     return false;
        // };
        priority_queue<pci, vector<pci>, comp> pq;

        for(int i = 0; i < n; i++){
            if(s[i] != '*'){
                pq.push({s[i], i});
            }
            else{
                // * mil gya, ab pq.top ko hame hatana h, to ham usko mark kr dete h
                auto [c, id] = pq.top();
                pq.pop();

                s[id] = '_';  // uss index ko mark kr diya jisko ham ans me nhi lenge
            }
        }

        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '*' || s[i] == '_') continue;
            else ans.push_back(s[i]);
        }

        return ans;
    }
};