struct comp {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const{
        if(a.first > b.first) return true;
        else if(a.first == b.first) return a.second < b.second;
        else return false;
    }
};
class FoodRatings {
public:
    map<string, pair<string, int>> mp;   // {ratings,cuisine} of each food
    map<string, set<pair<int, string>, comp>> mpp;  // set of pair of food and its ratings against each cuisine
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++){
            mp[foods[i]] = {cuisines[i], ratings[i]};
            mpp[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuis = mp[food].first;
        int prevRating = mp[food].second;

        mpp[cuis].erase({prevRating, food});
        mpp[cuis].insert({newRating, food});

        // update the latest rating in mp
        mp[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*mpp[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */