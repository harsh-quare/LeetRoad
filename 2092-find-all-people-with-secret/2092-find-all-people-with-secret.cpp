class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knowsSecret(n);
        knowsSecret[0] = knowsSecret[firstPerson] = 1;

        // sort the meetings by their time
        sort(meetings.begin(), meetings.end(), [&](const auto& m1, const auto& m2){
            return m1[2] < m2[2];
        });

        int meetingIdx = 0;
        int totalMeetings = meetings.size();

        while(meetingIdx < totalMeetings){
            // meetings happening at the same time => find range for current time
            int endCurrentMeetingIdx = meetingIdx;
            while(endCurrentMeetingIdx < totalMeetings && meetings[endCurrentMeetingIdx][2] == meetings[meetingIdx][2]){
                endCurrentMeetingIdx++;
            }

            unordered_map<int, vector<int>> adj;  // adjacency list for nodes having same time
            unordered_set<int> presentPeopleCurrTime;  // all the people in meeting at current time


            // create an adjacency list and also store the people in meeting at current time
            for(int idx = meetingIdx; idx < endCurrentMeetingIdx; idx++){
                int person1 = meetings[idx][0];
                int person2 = meetings[idx][1];

                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                presentPeopleCurrTime.insert(person1);
                presentPeopleCurrTime.insert(person2);
            }

            // using bfs to spread the secret through the connected component of current time
            queue<int> bfsQueue;
            for(auto& person: presentPeopleCurrTime){
                if(knowsSecret[person] == true){
                    bfsQueue.push(person);
                }
            }

            while(!bfsQueue.empty()){
                int currPerson = bfsQueue.front();
                bfsQueue.pop();
                
                // Share the secret to all the person meeting currentPerson
                for(auto& nbrPerson: adj[currPerson]){
                    if(!knowsSecret[nbrPerson]){
                        knowsSecret[nbrPerson] = true;
                        bfsQueue.push(nbrPerson);
                    }
                }
            }

            // move to next time group
            meetingIdx = endCurrentMeetingIdx;
        }

        // collect all the people who knows the secret
        vector<int> peopleWithSecret;
        for(int people = 0; people < n; people++){
            if(knowsSecret[people]){
                peopleWithSecret.push_back(people);
            }
        }

        return peopleWithSecret;
    }
};