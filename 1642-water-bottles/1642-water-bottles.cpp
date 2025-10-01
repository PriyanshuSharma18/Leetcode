class Solution {
public:
    static int numWaterBottles(int n, int k, int i=0) {
        return (n<k?0:n/k+numWaterBottles(n/k+n%k, k, i+1))+(i==0?n:0);
    }
};