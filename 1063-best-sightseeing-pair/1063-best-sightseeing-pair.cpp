#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("O3", "unroll-loops", "Ofast", "-ffloat-store")
static const auto harsh = []() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int maxi = values[0];

        for(int i = 1; i<values.size(); i++){
            ans = max(ans, (maxi + values[i]-i));
            maxi = max(maxi, values[i]+i);
        }

        return ans;        
    }
};