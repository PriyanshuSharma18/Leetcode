class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        static const unordered_set<char> vowels{'A', 'E', 'I', 'O', 'U'};
        unordered_set<string> words;
        unordered_map<string, string> capitalWords;
        unordered_map<string, string> vowelWords;

        for (const auto& word : wordlist) {
            words.insert(word);

            string upword(word);
            for (auto& c : upword) {
                c = toupper(c);
            }
            capitalWords.emplace(upword, word);

            for (auto& c : upword) {
                if (vowels.count(c)) {
                    c = '*';
                }
            }
            vowelWords.emplace(upword, word);
        }

        vector<string> res;
        for (const auto& query : queries) {
            if (words.count(query)) {
                res.push_back(query);
                continue;
            }

            string word(query);
            for (auto& c : word) {
                c = toupper(c);
            }
            if (capitalWords.count(word)) {
                res.push_back(capitalWords[word]);
                continue;
            }

            for (auto& c : word) {
                if (vowels.count(c)) {
                    c = '*';
                }
            }
            if (vowelWords.count(word)) {
                res.push_back(vowelWords[word]);
                continue;
            }
            res.push_back("");
        }
        return res;
    }
};