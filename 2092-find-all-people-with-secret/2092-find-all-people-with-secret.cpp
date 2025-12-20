class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knows(n, 0);
        knows[0] = knows[firstPerson] = true;

        sort(meetings.begin(), meetings.end(), [&](const auto& a, const auto& b){
            return a[2] < b[2];
        });

        int totalMeetings = meetings.size();
        int curIdx = 0;

        while(curIdx < totalMeetings){
            int endTimeIdx = curIdx;
            while(endTimeIdx < totalMeetings && meetings[endTimeIdx][2] == meetings[curIdx][2]){
                endTimeIdx++;
            }

            // adjacency list to create a graph for this time
            unordered_map<int, vector<int>> adj;

            for(int idx = curIdx; idx < endTimeIdx; idx++){
                int person1 = meetings[idx][0];
                int person2 = meetings[idx][1];

                adj[person1].push_back(person2);
                adj[person2].push_back(person1);
            }

            queue<int> q;
            // push all the guys in the curr time grp who knows the secret
            for(auto& [person,_]: adj){
                if(knows[person]){
                    q.push(person);
                }
            }

            while(!q.empty()){
                int curPerson = q.front();
                q.pop();

                for(auto& personNbr: adj[curPerson]){
                    if(!knows[personNbr]){
                        knows[personNbr] = true;
                        q.push(personNbr);
                    }
                }
            }

            // move to next time group
            curIdx = endTimeIdx;
        } 

        vector<int> res;
        for(int person = 0; person < n; person++){
            if(knows[person]){
                res.push_back(person);
            }
        }

        return res;
    }
};