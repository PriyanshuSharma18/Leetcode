class Solution {
public:
    int minimizedStringLength(string s) {
        int arr[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            int value = s[i] - 'a';
            arr[value] = 1;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i] == 1) count++;
        }
        return count;
    }
};