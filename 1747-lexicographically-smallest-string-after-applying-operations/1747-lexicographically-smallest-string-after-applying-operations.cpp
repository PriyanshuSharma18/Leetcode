class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        vector<int> vec = string2vec(s);
        vector<int> minVec = string2vec(s);
        vector<int> buffer (s.size(), 9);
        buffer.reserve(s.size());

        vector<int> aOffsets = getOffsets(a, 10);
        vector<int> bOffsets = getOffsets(b, s.size());

        if (b % 2 == 0) {
            for (int offset1: aOffsets) {
                for (int rot: bOffsets) {
                    applyOperations(vec, {0, offset1}, rot, buffer);
                    if (buffer < minVec) {minVec.assign(buffer.begin(), buffer.end()); }
                }
            }
        } else {
            for (int offset0: aOffsets) {
                for (int offset1: aOffsets) {
                    for (int rot: bOffsets) {
                        applyOperations(vec, {offset0, offset1}, rot, buffer);
                        if (buffer < minVec) {minVec.assign(buffer.begin(), buffer.end()); }
                    }
                }
            }
        }

        return vec2string(minVec);
    }
private:
    static constexpr int SEEN = 1;
    static constexpr int NOT_SEEN = 0;
    
    static vector<int> getOffsets(int step, int modulo) {
        vector<int> answer = {0};
        vector<int> seen (modulo, NOT_SEEN);
        int value = step % modulo;
        
        while (seen[value] == NOT_SEEN) {
            answer.push_back(value);
            seen[value] = SEEN;
            value = (value + step) % modulo;
        }

        return answer;
    }
    static vector<int> string2vec(const string& s) {
        vector<int> answer (s.size(), 0);
        for (int i = 0; i < s.size(); ++i) {answer[i] = s[i] - '0'; }
        return answer;
    }

    static string vec2string(const vector<int>& vec) {
        string s = "";
        s.reserve(vec.size());
        for (int v: vec) {s += (v + '0'); }
        return s;
    }

    static void applyOperations(const vector<int>& vec, const vector<int>& offsets, int rot, vector<int>& buffer) {
        for (int i = 0; i < vec.size(); ++i) {buffer[i] = (vec[i] + offsets[i % 2]) % 10; }
        if (rot != 0) {rotate(buffer.begin(), buffer.begin() + rot, buffer.end()); }
    }
};