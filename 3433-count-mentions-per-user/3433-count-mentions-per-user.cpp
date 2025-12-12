class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

        sort(events.begin(), events.end(), [](vector<string>& a, vector<string>& b){
            char evNameA = a[0][0];
            int timestampA = stoi(a[1]);

            char evNameB = b[0][0];
            int timestampB = stoi(b[1]);

            if(timestampA == timestampB){
                return (evNameA == 'O');
            }
            else return (timestampA < timestampB);
        });
        
        vector<int> offlines(numberOfUsers, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> offlineIdsTime;

        int all = 0;

        vector<int> mentionsCnt(numberOfUsers, 0);

        for(auto& event: events){
            char evName = event[0][0];
            int timestamp = stoi(event[1]);
            string ids = event[2];

            if(evName == 'M'){
                if(ids[0] == 'A'){
                    all++;
                }
                else if(ids[0] == 'H'){
                    // Only online ids should be mentioned
                    // but before mentioning onlines, check if any previously offline gets active or not?
                    while(!offlineIdsTime.empty() && offlineIdsTime.top().first <= timestamp){
                        auto p = offlineIdsTime.top();
                        offlineIdsTime.pop();
                        if(timestamp >= offlines[p.second]) offlines[p.second] = 0;   // mark back online
                    }
                    
                    // Now mark all the online ids
                    for(int i = 0; i < numberOfUsers; i++){
                        if(offlines[i] == 0) mentionsCnt[i]++;
                    }
                }
                else{
                    // GFG reference
                    // String variable i.e, string to be split => 'ids'

                    // variable to store token obtained from the original string
                    string s;

                    // constructing stream from the string
                    stringstream ss(ids);

                    // declaring vector to store the string after split
                    vector<string> v;

                    // using while loop until the getline condition is satisfied
                    // ' ' represent split the string whenever a space is found in the original string
                    while(getline(ss, s, ' ')){
                        // store token string in the vector
                        v.push_back(s);
                    }
                    for(int i = 0; i < v.size(); i++){
                        int id;
                        if(v[i].size() == 3){
                            id = v[i][2] - '0';
                        }
                        else{
                            id = stoi(v[i].substr(2,2));
                        }
                        
                        mentionsCnt[id]++;
                    }
                }
            }
            else{
                int id = stoi(ids);
                offlineIdsTime.push({timestamp + 60, id});  // put the id to the pq with next online time
                offlines[id] = timestamp + 60;  // and mark it offline
            }
        }

        for(int i = 0; i < numberOfUsers; i++){
            mentionsCnt[i] += all;
        }

        return mentionsCnt;
    }
};

// we need to maintain online ids
// we also need to maintain offline ids with their next online time


// 0,0,0
// 0,1,2
// all = 0 -> 1
// |{65,1},|126,1|


