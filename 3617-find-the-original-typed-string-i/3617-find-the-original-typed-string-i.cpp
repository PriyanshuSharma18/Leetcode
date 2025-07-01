class Solution {
public:
    static int possibleStringCount(string& word) {
        int n=word.size(), cnt=n;
        for(int i=1; i<n; i++)
            cnt-=(word[i]!=word[i-1]);
        return cnt;
    }
};