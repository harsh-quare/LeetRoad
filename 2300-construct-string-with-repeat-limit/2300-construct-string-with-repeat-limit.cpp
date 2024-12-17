class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>> pq;
        vector<int> cnt(26, 0);
        for(auto& ch: s){
            cnt[ch-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(cnt[i] != 0) pq.push({'a' + i, cnt[i]});
        }

        string ans = "";
        while (!pq.empty()) {
            //get the largest character
            char largest = pq.top().first;
            int freq = pq.top().second;
            pq.pop();

            //append `repeatLimit` or the remaining frequency
            int len = min(freq, repeatLimit);
            ans.append(len, largest);
            freq -= len;

            //check if the largest character has more occurrences left
            if(freq > 0){
                //if there is no second largest character, we cannot proceed
                if(pq.empty()) break;

                //get the second largest character
                char secondLarg = pq.top().first;
                int f = pq.top().second;
                pq.pop();

                //append one instance of the second largest character
                ans += secondLarg;
                f--;

                //push the second largest back if it still has occurrences left
                if(f > 0){
                    pq.push({secondLarg, f});
                }

                //push the largest character back with its remaining frequency
                pq.push({largest, freq});
            }
            //if no more occurrences of the largest character, continue naturally
        }

        return ans;
    }
};