class LRUCache {
private:
struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v):key(k),val(v),prev(nullptr),next(nullptr){}
};
int capacity;
unordered_map<int,Node*>mp;
Node* head;
Node* tail;
void remove(Node* node){
    if(!node){return;}
    if(node->prev){
        node->prev->next=node->next;
    }
    if(node->next){
        node->next->prev=node->prev;
    }
}
void InsertAfterHead(Node* node){
    Node* next_node=head->next;
    head->next=node;
    node->prev=head;
    node->next=next_node;
    next_node->prev=node;
}
public:

    LRUCache(int capacity) {
        this->capacity=capacity;
        head =new Node(-1,-1);//create dummy head node
        tail=new Node(-1,-1);//create dummy tail node
        head->next=tail;
        tail->prev=head; 
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* node=mp[key];
        remove(node);
        InsertAfterHead(node);  
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->val=value;
            remove(node);
            InsertAfterHead(node);
            return;
        }
        if(mp.size()==capacity){//need to remove LRU cache
        Node* lru=tail->prev;//tail is dummy node
        remove(lru);
        mp.erase(lru->key);
        delete(lru);
        }
        Node* newnode=new Node(key,value);
        InsertAfterHead(newnode);
        mp[key]=newnode;
        return;
    }
};

