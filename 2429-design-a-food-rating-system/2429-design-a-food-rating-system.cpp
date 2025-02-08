class FoodRatings {
public:

    unordered_map<string, set<pair<int, string>>> cuisineRatings;  // cuisines -> set{-rating, food} => -rating, bcz we will need the max rating, and set stores in ascending order, so once negative, the max rating will be at beginning.
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodToCuisine;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            string f = foods[i];
            int r = ratings[i];
            string c = cuisines[i];

            cuisineRatings[c].insert({-r, f});
            foodRating[f] = r;
            foodToCuisine[f] = c;
        }
    }
    
    void changeRating(string food, int newRating) {
        auto cuis = foodToCuisine[food];  //grab the cuisine for current food
        int oldRating = foodRating[food];
        cuisineRatings[cuis].erase({-oldRating, food});  //erase the old rating, food pair from that cuisine
        
        cuisineRatings[cuis].insert({-newRating, food});  //insert new rating, food pair
        foodRating[food] = newRating;  // and also update that food rating
    }
    
    string highestRated(string cuisine) {
        return (*cuisineRatings[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */