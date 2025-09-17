class FoodRatings {
public:
struct CustomPairCompare {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first != b.first) {
            return a.first > b.first; 
        }
        return a.second < b.second;
    }
};
    unordered_map<string,int> foodToRatings;
    unordered_map<string,string> foodToCuisine;
    unordered_map<string,set<pair<int,string>,CustomPairCompare>> cuisineToSet;


    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int numberOfItems = foods.size();
        for(int i=0;i<numberOfItems;i++){
            foodToRatings[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
            cuisineToSet[cuisines[i]].insert({ratings[i],foods[i]});
        }

    }
    
    void changeRating(string food, int newRating) {
        int oldRating  = foodToRatings[food];
        foodToRatings[food] = newRating;
        string Cuisine = foodToCuisine[food];
        cuisineToSet[Cuisine].erase({oldRating,food});
        cuisineToSet[Cuisine].insert({newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto it = next(cuisineToSet[cuisine].begin(),0);
        pair<int,string> pr=*it;
        return pr.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */