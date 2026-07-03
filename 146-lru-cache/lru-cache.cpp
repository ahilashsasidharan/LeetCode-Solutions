class LRUCache {

protected:

int capacity;
std::list<pair<int,int>> accessList;
std::unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }

        accessList.splice(accessList.begin(), accessList, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            cache[key]->second = value;
            accessList.splice(accessList.begin(), accessList, it->second);
            return;
        }

        if(accessList.size() >= capacity){
            auto endIt = prev(accessList.end());
            cache.erase(endIt->first);
            accessList.erase(endIt);
        }

        accessList.emplace_front(key, value);
        cache[key] = accessList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */