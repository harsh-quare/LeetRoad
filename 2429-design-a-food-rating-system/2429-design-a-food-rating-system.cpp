class FoodRatings {
public:
    struct Cmp {
        bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };

    unordered_map<string, pair<string, int>> dish;
    unordered_map<string, set<pair<string, int>, Cmp>> currRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            dish[foods[i]] = {cuisines[i], ratings[i]};
            currRating[cuisines[i]].insert({foods[i], ratings[i]});
        }
    }

    void changeRating(string food, int newRating) {
        pair<string, int> curr = dish[food];
        currRating[curr.first].erase({food, curr.second});
        currRating[curr.first].insert({food, newRating});
        dish[food] = {curr.first, newRating};
    }

    string highestRated(string cuisine) {
        return currRating[cuisine].begin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */