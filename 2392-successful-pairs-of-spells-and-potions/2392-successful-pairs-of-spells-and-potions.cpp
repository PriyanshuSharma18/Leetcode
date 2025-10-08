
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;

        for (int i = 0; i < spells.size(); ++i) {
            long long spell = spells[i];
            if (spell == 0) {
                ans.push_back(0);
                continue;
            }
            long long need = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            int idx = it - potions.begin();
            ans.push_back(m - idx);
        }
        return ans;
    }
};