#include<string>
#include<vector>
using namespace std;

class Kmp
{
  public:
    static vector<int> find(const string &str, const string &substr){
        vector<int> next = getNext(substr);
        vector<int> ret = getkmp(str,substr);
        return ret;
    }
    static vector<int> getNext(const string &substr){
        vector<int> next;
        next.resize(substr.size());
        int j = -1;
        next[0] = -1;
        for (int i = 1; i < substr.size(); ++i){
            while (j > -1 && substr[j + 1] != substr[i])
                j = next[j];
            if (substr[j + 1] == substr[i])
                ++j;
            next[i] = j;
        }
        return next;
    }
  private:
    static vector<int> getkmp(const string &str, const string &substr){
        vector<int> ret;
        vector<int> next = getNext(substr);
        int j = -1;
        for (int i = 0; i < str.size(); ++i){
            while (j > -1 && substr[j + 1] != str[i])
                j = next[j];
            if (substr[j + 1] == str[i])
                ++j;
            if (j == substr.size() - 1){
                ret.push_back( i - substr.length() + 1 ); // find in position 
                j = next[j];
            }
        }
        return ret;            
    }
};