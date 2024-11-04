#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        char prev = word[0];
        int count = 1;

        for (int i = 1; i < word.size(); i++) {
            if (prev != word[i]) {
                ans += to_string(count);
                ans += prev;
                count = 1;
                prev = word[i];
            } else {
                if (count == 9) {
                    ans += to_string(count);
                    ans += prev;
                    count = 1;
                } else {
                    count += 1;
                }
            }
        }
        ans += to_string(count);
        ans += prev;

        return ans;
    }
};