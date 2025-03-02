#include <iostream>
#include <list>
#include <unordered_map>
#include <memory>

using namespace std;

struct CacheItem {
    int key;
    int value;

    CacheItem(int k, int v) : key(k), value(v) {}
};

struct LRUCache {
    int capacity;
    list<shared_ptr<CacheItem>> cacheList;
    unordered_map<int, weak_ptr<CacheItem>> cacheMap;

    LRUCache(int cap) : capacity(cap) {}

    void moveToFront(shared_ptr<CacheItem> item) {
        cacheList.remove(item);
        cacheList.push_front(item);
    }

    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end() || it->second.expired()) {
            return -1; // Key not found
        }
        auto item = it->second.lock();
        moveToFront(item);
        return item->value;
    }

    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end() && !it->second.expired()) {
            auto item = it->second.lock();
            item->value = value;
            moveToFront(item);
        } else {
            if (cacheList.size() == capacity) {
                auto last = cacheList.back();
                cacheMap.erase(last->key);
                cacheList.pop_back();
            }
            auto newItem = make_shared<CacheItem>(key, value);
            cacheList.push_front(newItem);
            cacheMap[key] = newItem;
        }
    }

    void display() {
        for (auto& item : cacheList) {
            cout << item->key << " ";
        }
        cout << endl;
    }
};

int main() {
    LRUCache cache(4);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(1, 1); // Access key 1
    cache.put(4, 4);

    cout << "Cache actuel :" << endl;
    cache.display();

    cache.put(5, 5); // This should evict key 2

    cout << "Accès à la clé 5 -> Eviction de la clé 2" << endl;
    cout << "Cache actuel :" << endl;
    cache.display();

    return 0;
}