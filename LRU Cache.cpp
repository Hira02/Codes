/*
Problem Description : (LC 146)
------------------------------------------------------------------------------------
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/
Code:
----------------------------------------------------------------------------------------------------------
class ListNod{
  public:  
    int val;
    ListNod* prev, *next;
    ListNod(int x) : val(x), prev(NULL), next(NULL) {}
};
class LRUCache {
public:
    ListNod* head = NULL;
    ListNod* tail = NULL;
    unordered_map<int, pair<ListNod*, int>> Map;
    int size = 0;
    int len = 0;
    LRUCache(int capacity) {
        size = capacity;
    }
    void checkLastNode(){
        // cout<<tail->val<<" ";
        if(tail == NULL) return ;
        if(tail->prev) tail->prev->next = NULL;
        else
            head = NULL;
        ListNod* temp = tail;
        tail = tail->prev;
        Map.erase(temp->val);
        delete(temp);
        len--;
    }
    int get(int key) {
        // auto it = Map[key];
        if(Map.find(key) == Map.end()) return -1;
        ListNod* ptr = Map[key].first;
        // cout<<"ptr "<<ptr->val<<" ";
        if(ptr == head) return Map[ptr->val].second;
        if(ptr->prev) ptr->prev->next = ptr->next;
        if(ptr->next) ptr->next->prev = ptr->prev;
        else
            tail = ptr->prev;
        ptr->next = head;
        if(head) head->prev = ptr;
        head = ptr;
        return Map[ptr->val].second;
     }
    
    void put(int key, int value) {
        // auto it = Map[key];
        if(Map.find(key) != Map.end()){
            // cout<<Map[key].second<<" ";
            Map[key].second = value;
            get(key);
            return ;
        }
        if(len == size)
            checkLastNode();
        // cout<<len<<" ";
        ListNod* newNode = new ListNod(key);
        newNode->next = head;
        if(head) head->prev = newNode;
         head = newNode;
        if(tail == NULL) tail = newNode;
       
        Map[key] = make_pair(newNode, value);
        len++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
