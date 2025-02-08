class FoodRatings {
public:
    map<string, pair<string, int>> FtoCandR;
    map<string, map<int, set<string>>> CtoRandF;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            FtoCandR[foods[i]] = {cuisines[i], ratings[i]};
            CtoRandF[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto foodInfo = FtoCandR.find(food);
        string cuisine = foodInfo->second.first;
        int prevRating = foodInfo->second.second;
        foodInfo->second.second = newRating;

        CtoRandF[cuisine][prevRating].erase(food);
        if(CtoRandF[cuisine][prevRating].empty()) CtoRandF[cuisine].erase(prevRating);

        CtoRandF[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *CtoRandF[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */