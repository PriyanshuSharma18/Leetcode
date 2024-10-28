const long long N=100001;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        bitset<N> hasX=0;
        for(int x: nums)
            hasX[x]=1;
        int maxStreak=0;
        for(long long x: nums){
            int streak=1;
            for(long long z=x*x; z<N; z*=z)
                if (hasX[z]) streak++;
                else break;
            maxStreak=max(maxStreak, streak);
            if (maxStreak==5) break;
        }
        return maxStreak<2?-1:maxStreak;
    }
};