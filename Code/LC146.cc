// LRU缓存机制

class LRUCache {
public:
    struct Node
    {
        int val, key;
        struct Node* next;
        struct Node* prev;

        Node(int k, int v)
        {
            key = k;
            val = v;
            next = prev = nullptr;
        }
    };

    Node* head;     // 双向链表头哨兵节点
    Node* tail;     // 尾哨兵节点
    int C;          // 最大容量
    unordered_map<int, Node*> pos;

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        C = capacity;
    }
    
    int get(int key) {
        // 如果不存在则返回-1
        if(!pos.count(key)) return -1;

        // 存在则更新节点
        Node* ptr = pos[key];
        remove(ptr);
        insert(ptr);
        return ptr->val;
    }
    
    void put(int key, int value) {
        // 如果存在，则变更数据
        if(pos.count(key))
        {
            // 更新数据、时间
            Node* ptr = pos[key];
            ptr->val = value;
            remove(ptr);
            insert(ptr);
            return;
        }
        // 如果不存在，则插入
        // 如果没满则直接插入，如果满了则逐出最久未使用的关键字，并插入新关键字
        if(pos.size() == C)
        {
            Node* prev = tail->prev;
            remove(prev);
            pos.erase(prev->key);
            delete prev;
        }
        Node* ptr = new Node(key, value);
        pos[key] = ptr;
        insert(ptr);
    }

    void remove(Node* node)
    {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
        node->next = node->prev = nullptr;
    }

    void insert(Node* node)
    {
        Node* a = head->next;
        head->next = node;
        node->prev = head;
        node->next = a;
        a->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */