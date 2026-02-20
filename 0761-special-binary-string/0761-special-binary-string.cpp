class Solution {
public:
    // pair<uint64_t, uint8_t> -> (x, width)
    using int2=pair<uint64_t, uint8_t>;

    static int2 dfs(string& s, int l0, int end) {
        // If l0>end, it's an empty string
        if (l0>end) return {0, 0};

        int balance=0;
        vector<int2> nums;
        int l=l0;

        for (int r=l0; r<=end; r++) {
            balance+=(s[r]=='1')*2-1;
            if (balance==0) {
                // Recursively solve the inner part
                auto [x, w]=dfs(s, l+1, r-1);
                
                int len=r-l+1;
                // Wrap inner result: '1' + [x] + '0'
                nums.emplace_back((1ULL<<(len-1))+(x<<1), len);
                l=r+1;
            }
        }

        // Sort wrt lexico order using MSB alignment trick
        sort(nums.begin(), nums.end(), 
            [](const auto& X, const auto& Y) {
                uint64_t x=X.first, y=Y.first;
                uint8_t wx=X.second, wy=Y.second;
                uint64_t sx=x<<(64-wx);
                uint64_t sy=y<<(64-wy);
                if (sx!= sy) return sx>sy;
                return wx>wy;
        });

        // Construct ans
        uint64_t ans=0;
        uint8_t len=0;
        for (auto& [x, width] : nums) {
            ans=(ans<<width)+x;
            len+=width;
        }
        return {ans, len};
    }

    static string makeLargestSpecial(string& s) {
        if (s=="10") return s;
        const int n=s.size();
        auto [num, len]=dfs(s, 0, n-1);
        return bitset<64>(num).to_string().substr(64-n);
    }
};