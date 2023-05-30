class Solution {
  public:
    Solution(int capacity) : capacity(capacity) {}
    void debug() {
        for (int i = 0; i < lru_lazy.size(); i++) {
            cout << lru_lazy[i] << " ";
        }
        cout << endl;
    }
    int get(int key) {
        if (lru_index.count(key) == 0) {
            return -1;
        }
        for (int i = 0; i < lru_lazy.size(); i++) {
            if (lru_lazy[i] == key) {
                lru_lazy.erase(lru_lazy.begin() + i);
                lru_lazy.emplace_back(key);
            }
        }
        return lru[lru_index[key]].value;
    }

    void set(int key, int value) {
        if (lru_index.count(key) == 0) {
            if (lru_lazy.size() >= capacity) {
                int key_old = lru_lazy.front();
                lru_lazy.erase(lru_lazy.begin());
                lru_index.erase(key_old);
            }
            Node node(value, lru.size());
            lru_index[key] = lru.size();
            lru.emplace_back(std::move(node));
            lru_lazy.emplace_back(key);
        } else {
            Node node(value, lru.size());
            lru_index[key] = lru.size();
            lru.emplace_back(std::move(node));

            for (int i = 0; i < lru_lazy.size(); i++) {
                if (lru_lazy[i] == key) {
                    lru_lazy.erase(lru_lazy.begin() + i);
                    lru_lazy.emplace_back(key);
                }
            }
        }
    }

  private:
    struct Node {
        int value;
        int index;
        Node(int value, int index) : value(value), index(index) {};
    };
    int capacity;
    vector<Node> lru;
    map<int, int> lru_index;
    deque<int> lru_lazy;
};