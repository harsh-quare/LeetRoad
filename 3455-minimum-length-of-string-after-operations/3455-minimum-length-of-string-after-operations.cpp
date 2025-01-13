class Solution {
public:
    int minimumLength(string s) {
        // agar kisi bhi character ki freq 3, ya 3 se jyada h to woh to 100% delete ho skte h, and hame mtlb nhi h ki kese hoga, hame just length se matlab h, to bs len-3 ho jayega
        // Just check ki kitne chars h jinki freq >= 3 h

        vector<int> freq(26, 0);
        for(auto& ch: s){
            freq[ch-'a']++;
        }

        int len = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] <= 2) len += freq[i];
            else{    // if(freq[i] > 2)        
                if(freq[i] % 2 != 0) len += 1;  // agar 3,5,7 aisa kuch h, to saare pairs left right se nikal jayenge, ek bach jayega
                else len += 2;  // otherwise, agar 4,6,8 aisa h, to hamesha last me 2 bach jayenge, baaki sab nikal jayenge pair banke
            }
        }

        return len;
    }
};

// 3, 4 ke liye len-=2 => (3+1)/2 = 2, (4+1)/2 = 2
// 5, 6 ke liye len-=3 => (5+1)/2 = 3, (6+1)/2 = 3