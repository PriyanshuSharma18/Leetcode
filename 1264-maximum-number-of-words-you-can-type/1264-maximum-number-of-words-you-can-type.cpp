class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters){
        unordered_set<char> st;
        int cnt = 0;

        for(auto& it : brokenLetters){
            st.insert(it);
        }

        stringstream ss(text);

        string word;
        vector<string> words;

        while(ss >> word){
            words.push_back(word);
        }

        for(auto w: words)
        {
            for(char c : w)
            {
                if(st.find(c) != st.end())
                {
                    cnt++;
                    break;
                }
            }
        }

        return words.size() - cnt;
    }
};