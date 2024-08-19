class Solution {
public:
    void fs(string &str1, string str2) {
        
        int f = str1.find(']');
        if (f == string::npos) return; 
        
        
        int i;
        for (i = f; i >= 0; i--) {
            if (str1[i] == '[') break;
        }

        
        int num = 0, multiplier = 1;
        int j = i - 1;
        while (j >= 0 && isdigit(str1[j])) {
            num += (str1[j] - '0') * multiplier;
            multiplier *= 10;
            j--;
        }


        string str3 = str1.substr(i + 1, f - i - 1);

        
        str2.clear(); 
        for (int h = 0; h < num; h++) {
            str2 += str3;
        }

        
        str1 = str1.substr(0, j + 1) + str2 + str1.substr(f + 1);

        
        fs(str1, str2);
    }

    string decodeString(string s) {
        string m = "";
        fs(s, m);
        return s;
    }
};

