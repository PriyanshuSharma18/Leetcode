class Solution {
public:
    int countZeros(long long n) {
    if (n == 0) return 1; // special case
    int count = 0;
    while (n > 0) {
        if (n % 10 == 0) count++;
        n /= 10;
    }
    return count;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            if (countZeros(i) == 0 && countZeros(n-i)==0){
                ans = {i, n-i};
                break;
            }
        }
        return ans;
    }
};