struct Node{
  int key;
  int value;
  Node* next;
  Node* prev;
  Node(int k, int v){
    key = k;
    value = v;
    next = nullptr;
    prev = nullptr;
  }  
};
class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    void move_back(Node* curr){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        tail->prev->next = curr;
        curr->prev = tail->prev;
        curr->next = tail;
        tail->prev = curr;
    }

    void drop_first(){
        Node* dropNode = head->next;
        cache.erase(dropNode->key);
        head->next = head->next->next;
        head->next->prev = head;
    }
    void add_back(Node* newNode){
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev = newNode;
        cache[newNode->key] = newNode;
    }

    int get(int key) {
        if(cache.count(key)){
            Node* curr = cache[key];
            move_back(curr);
            return curr->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            Node* curr = cache[key];
            curr->value = value;
            move_back(curr);
        }
        else{
            Node* newNode = new Node(key, value);
            if(cache.size() == cap){
                drop_first();
                add_back(newNode);
            }
            else{
                add_back(newNode);
            }
        }
    }
};
