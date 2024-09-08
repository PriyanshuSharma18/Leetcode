class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs;

        sort(potions.begin(), potions.end());

        for(int i = 0; i < n; i++)
            pairs.push_back(m - (lower_bound(potions.begin(), potions.end(), (double)success / spells[i]) - potions.begin()));

        return pairs;
    }
};