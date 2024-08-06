class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        gain.insert(gain.begin(), 0);
        std::partial_sum(gain.begin(), gain.end(), gain.begin());
        return *std::max_element(gain.begin(), gain.end());
    }
};