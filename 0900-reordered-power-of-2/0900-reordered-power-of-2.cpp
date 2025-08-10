class Solution {
public:
    unordered_set<string> st;
    void buildSet(){
        // from p = 0 to 30
        // convert to string, and sort it
        // the store in set
        for(int p = 0; p <= 30; p++){
            string s = to_string(1 << p);
            sort(s.begin(), s.end());

            st.insert(s);
        }
    }

    bool reorderedPowerOf2(int n) {
        if(st.empty()){  // ensuring, we call it only once
            buildSet();  
        }

        string s = to_string(n);
        sort(s.begin(), s.end());

        if(st.count(s)) return true;
        else return false;
    }
};