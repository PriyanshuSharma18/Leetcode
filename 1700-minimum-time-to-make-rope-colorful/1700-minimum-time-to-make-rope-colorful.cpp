class Solution {
public:
    static int minCost(string& colors, vector<int>& neededTime) {
        int l=0, r;
        const int n=colors.size();
        int removes=0, locMax=0;
        for (r=0; r<n; ) {
            while (r<n && colors[r]==colors[l]) {
                removes+=neededTime[r];
                locMax=max(locMax, neededTime[r]);
                r++;
            }
        //    cout << "l=" << l << " locMax=" << locMax << endl;
            removes-= locMax;
            locMax=0;
            l=r; 
        }
        return  removes;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();