class Solution {
public:
    bool getBit(int x, int k) {
        return (x >> k) & 1;
    }

    bool check(string word, int flag) {
        for (char c : word)
            if (!getBit(flag, c - 'a'))
                return false;
        return true;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        int flag = 0;
        for (char c : allowed)
            flag |= 1 << (c - 'a');

        int res = 0;
        for (string word : words) 
            if (check(word, flag))
                res++;
        return res;
    }
};