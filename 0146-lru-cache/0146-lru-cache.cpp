class Node{
public: 
    int key, value;
    Node* next;
    Node* prev;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
private: 
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> keyNodeMap;

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node){
        Node* currentAfterHead = head->next;
        node->next = currentAfterHead;
        currentAfterHead->prev = node;
        node->prev = head;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        keyNodeMap.clear();

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(keyNodeMap.find(key) == keyNodeMap.end()){
            return -1;
        }
        
        Node* node = keyNodeMap[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }
    
    void put(int key, int value) {
        if(keyNodeMap.find(key) != keyNodeMap.end()){
            // already have it => update
            Node* node = keyNodeMap[key];
            node->value = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            // create new node and insert
            if(keyNodeMap.size() == capacity){
                // remove least recently used node => tail->prev
                Node* leastRecent = tail->prev;
                keyNodeMap.erase(leastRecent->key);
                deleteNode(leastRecent);
            }
            
            // add it after head   
            Node* node = new Node(key, value);
            keyNodeMap[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */