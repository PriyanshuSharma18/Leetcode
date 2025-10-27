class Solution {
public:
    int countChar(std::string_view str, char target)
    {
        int res {0};
        for (const char c : str)
        {
            if (c == target)
                res++;
        }
        return res;
    }

    int numberOfBeams(vector<string>& bank) {
        int res {0};
        int last {0};
        int curr {0}; 

        for (const std::string_view str : bank)
        {
            curr = countChar(str, '1');

            if (curr != 0)
            { 
                res += last * curr;
                last = curr;
            }
        }

        return res;
    }
};