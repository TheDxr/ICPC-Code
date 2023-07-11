class LRUCache
{
public:
    LRUCache(int capacity) { lru.resize(capacity, -1, -1); }

    int get(int key)
    {
        if(lru_map.count(key) == 0) {
            return -1;
        }
        else {
            ListNode *node = lru_map[key];
            lru.move_front(node);
            lru_map[key] = lru.front;
            return lru.front->val;
        }
    }
    void put(int key, int value)
    {
        if(lru_map.count(key)) {
            ListNode *node = lru_map[key];
            lru.move_front(node);
            lru_map[key] = lru.front;
            lru.front->val = value;
        }
        else {
            lru_map.erase(lru.back->key);
            lru.push_front(key, value);
            lru.remove(lru.back);
            lru_map.insert({key, lru.front});
        }
    }

private:
    struct ListNode
    {
        int key;
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr){};
        void operator delete (void *p) { ((ListNode*)p)->key = -1;((ListNode*)p)->val = -1; }
    };
    struct List
    {
        ListNode *front{};
        ListNode *back{};
        List() : front(nullptr), back(nullptr){};
        void push_front(int key, int val)
        {
            auto *node = new ListNode(key, val);
            if(front == nullptr) {
                front = node;
                back  = node;
            }
            else {
                node->next = front;
                front->prev = node;
                front = node;
            }
        }
        void remove(ListNode *node)
        {
            if(node == nullptr) return;
            if(node == back) {
                node->prev->next = nullptr;
                back = node->prev;
            }
            else if(node == front) {
                node->next->prev = nullptr;
                front = node->next;
            }
            else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            delete node;
        }
        void move_front(ListNode *node)
        {
            push_front(node->key, node->val);
            remove(node);
        }
        void resize(int n, int key, int val)
        {
            for(int i = 0; i < n; ++i) {
                push_front(key, val);
            }
        }
        string to_string() const
        {
            string ans;
            for(auto *node = front; node != nullptr; node = node->next) {
                ans += std::to_string(node->key) + ":" + std::to_string(node->val) + " ";
            }
            return ans;
        }
    };
    List lru;
    unordered_map<int, ListNode *> lru_map;
};