class AllOne {
public:

    struct Node{
        int freq;  //frequency of string
        unordered_set<string> st;
        Node* prev;
        Node* next;

        Node(int cnt){
            freq = cnt;
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<string, Node*> mp;  //string is the key and the value is the address(pointer) where it's stored in doubly Linked List

    Node* head;  //head of LL, count 0 store krega. For getting minKey, we will be using head->next
    // Node* first; //minKey string
    Node* last;  //maxKey string

    AllOne() {
        head = new Node(0);
        last = head;  //last node bhi head hi h, abhi ke liye
    }

    void addNode(Node* prevNode, int cnt){
        Node* newNode = new Node(cnt);

        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;
        }
        prevNode->next = newNode;

        if(prevNode == last){
            last = newNode;
        }
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        if(node->next != NULL){
            node->next->prev = node->prev;
        }

        if(last == node){
            last = node->prev;
        }

        delete node;
    }
    
    void inc(string key) {
        if(mp.find(key) == mp.end()){
            //The string does not exist in the map
            //check if there is already a node with freq = 1

            //if head is the only node present or the next node after head is not with freq=1
            if(head->next == NULL || head->next->freq != 1){
                //create new node with freq=1, insert in the LL and store string in that node
                addNode(head, 1);  //head->next = newNode  //head ke aage ek node bana or uska count 1 de
            }

            head->next->st.insert(key);
            mp[key] = head->next;
        }
        else{
            //key is already present in the map and have some frequency
            //increase its frequency by 1
            //check if freq+1 node exist or not, and then same as above
            Node* curr = mp[key];
            int cnt = curr->freq;
            if(curr->next == NULL || curr->next->freq != cnt + 1){
                //jis freq wale node pe bethe ho, uske next wali node h hi nahi
                addNode(curr, cnt + 1);  //curr ke baad ek node bana and uska count cnt+1 de
            }
            
            curr->next->st.insert(key);
            mp[key] = curr->next;
            curr->st.erase(key);
            if(curr->st.empty()){
                //koi string stored nahi h iss freq wale node me, delete kr do iss node ko
                removeNode(curr);
            }
        }
    }
    
    void dec(string key) {
        Node* curr = mp[key];
        int cnt = curr->freq;

        //remove the key if count becomes zero
        if(cnt == 1){  // 1-1 = 0, freq kam hoke zero ho jayegi
            mp.erase(key);
        }
        else{
            //check kro ki cnt-1 wali node exist krti h ki nahi, 
            //agar nahi krti h to, cnt-1 wali node create krni padegi   
            if(curr->prev->freq != cnt - 1){
                //create the node with freq=cnt-1
                // 1-> 2-> 4-> 5  //lets say cnt = 4, ab cnt=3 check kiya, to woh to nahi mila, to ab curr->prev = 2 ke aage ek node lagani h with count = cnt-1
                addNode(curr->prev, cnt-1);  //curr ke prev node ke baad ek node bana 
            }

            curr->prev->st.insert(key);
            mp[key] = curr->prev;
        }
        curr->st.erase(key);
        if(curr->st.empty()){
            removeNode(curr);
        }
    }
    
    string getMaxKey() {
        if(last == head){
            //no nodes available
            return "";
        }
        auto it = last->st.begin();
        return *it;
    }
    
    string getMinKey() {
        if(head->next == NULL){
            return "";
        }
        auto it = head->next->st.begin();
        return *it;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */