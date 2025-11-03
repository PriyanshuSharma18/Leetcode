class Solution {
public:
    int minCost(string& colors, vector<int>& neededTime) {
        const int n=colors.size();
        int removes=0;
        int locMax=neededTime[0], sum=neededTime[0];
        for (int r=1; r<n; r++) {
            const int x=neededTime[r];
            const bool sameColor=colors[r]==colors[r-1];
            removes+=(sum-locMax)&(-!sameColor);
            sum=x+(sum & -sameColor);
            locMax=max((locMax & -sameColor), x); 
        }
        removes+=sum-locMax; //last group
        return removes;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();