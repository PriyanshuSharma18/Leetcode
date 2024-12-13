class Solution {
public:
    #define ll long long
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        ll sum = 0;
        vector<int> vis(nums.size());
        while (!pq.empty()) {
            if (vis[pq.top().second]) {
                pq.pop();
            } else {
                int ind = pq.top().second;
                sum += pq.top().first;
                pq.pop();
                vis[ind] = 1;
                if (ind - 1 >= 0) vis[ind - 1] = 1;
                if (ind + 1 < n) vis[ind + 1] = 1;
            }
        }
        return sum;
    }
};