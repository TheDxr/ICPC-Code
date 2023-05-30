class Solution {
  public:
    bool isMatch(string s, string p) {
        bool flag = false;
        int j = 0, i = 0;
        while(i <= s.size()) {
   //         cout << s.substr(i) << " || " << p.substr(j) << endl;
            if(j + 1 < p.size() && p[j + 1] == '*') {
                if(p[j] == '.') {
                    while(i < s.size() && !isMatch(s.substr(i), p.substr(j + 2)))
                        i++;
                }
                else {
                    while(i < s.size() && s[i] == p[j] && !isMatch(s.substr(i), p.substr(j + 2)))
                        i++;
                }
                j += 2;
                continue;
            }
            else if(p[j] == '.' && i < s.size()){
                j++;
                i++;
                continue;
            }
            else if(s[i] == p[j] && i < s.size()){
                j++;
                i++;
                continue;
            }
            break;
        }
        if(i >= s.size() && j >= p.size()) {
            flag = true;
        }
        return flag;
    }
};