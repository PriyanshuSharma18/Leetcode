#include <queue>
#include <vector>
#include <cmath>

class Solution {
public:
    long long pickGifts(std::vector<int>& gifts, int k) {
        std::priority_queue<int> pq(gifts.begin(), gifts.end());
        for (int i = 0; i < k; ++i) {
            int gift = pq.top();
            pq.pop();
            int left = static_cast<int>(std::floor(std::sqrt(gift)));
            pq.push(left);
        }
        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};