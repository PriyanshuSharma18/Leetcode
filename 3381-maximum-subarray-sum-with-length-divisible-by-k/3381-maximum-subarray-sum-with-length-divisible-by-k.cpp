#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefix = 0;
        const long long INF = (long long)1e18;
        vector<long long> min_pre(k, INF);
        min_pre[0] = 0;
        long long ans = -INF;
        for (int j = 1; j <= n; ++j) {
            prefix += nums[j-1];
            int r = j % k;
            if (min_pre[r] != INF) {
                long long cand = prefix - min_pre[r];
                if (cand > ans) ans = cand;
            }
            if (prefix < min_pre[r]) min_pre[r] = prefix;
        }
        return ans;
    }
};