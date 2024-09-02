class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0;
        if (chars.size() == 1) {
            return 1;
        }
        vector<char> v;
        
        char c = chars[0];
        for (int j = 0; j < chars.size(); j++) {
            if (c == chars[j]) {
                count++;
            } 
            else {
                if (count == 1) {
                    v.push_back(c);
                    count = 1;
                } 
                else {
                    v.push_back(c);
                    string s = to_string(count);
                    for (char ch : s) {
                        v.push_back(ch);
                    }
                    count=1;
                }
                c=chars[j];
            }
        }
        v.push_back(c);
        if(count>1){
            string s = to_string(count);
            for (char ch : s) {
                v.push_back(ch);
            }
        }
        chars = v;
        return v.size();
    }
};