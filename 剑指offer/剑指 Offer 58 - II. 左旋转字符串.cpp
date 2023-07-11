class Solution {
public:
    string reverseLeftWords(string s, int n) {
        s.append(s.substr(0, n));
        s.erase(0, n);
        return s;
    }
};