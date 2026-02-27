class Solution {
public:
    int minOperations(string s, int k) {
        long long n = s.size(), z = 0, ans = -1;
        // Count no. of zeroes
        for (long long i=0; i<n; i++) {
            if(s[i] == '0') {
                z++;
            }
        }
        // If no. of zeroes are null then directly return 0 (i.e. string is 111....11111)
        if(z == 0) {
            return 0;
        }
        // Run loop from i=1 to n
        for(long long i=1; i<=n; i++) {
            // Check 3 conditions : 
            // 1) is i*k greater than equal to no. of zeroes 
            // 2) is i*k has same remainder as no. of zeroes ? (Parity)
            // 3) is max operations (i.e. i*k) are less than maximum operations ??
                // Max Operations : (For Odd) (No. of 0s * i) + (n - No. of 0s (i.e. No. of 1s) * i-1)
                //                  (For Even) (No. of 0s * i-1) + (n - No. of 0s (i.e. No. of 1s) * i)
            if((i*k >= z) && ((i*k)%2 == z%2) && ((i*k) <= ((i%2) == 0 ? ((z*(i-1)) + ((n-z) * i)) : ((z*i) + ((n-z) * (i-1)))))) {
                // If all conditions are true , update ans with m and break;
                ans = i;
                break;
            }
        }
        return ans;
    }
};