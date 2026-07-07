class LRUCache {
public:
    class Node {
    public:
        int val;
        int key;
        Node* next;
        Node* prev;

Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
        }
    };

    int cap ;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;

    void addNode(Node* newNode) {
        Node* temp = head->next;
       newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (m.find(key) == m.end())
            return -1;

        Node* temp = m[key];
        int res = temp->val;

        m.erase(key);
        deleteNode(temp);
        addNode(temp);
        m[key] = head->next;
        return res;
    }

    void put(int key, int value) {

        if (m.find(key) != m.end()) {
            Node* temp = m[key];
            m.erase(key);
            deleteNode(temp);
            delete temp;
        } else if (m.size() == cap) {
            Node* temp = tail->prev;
             m.erase(temp->key);
            deleteNode(temp);
            delete temp;
        }
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = head->next;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */