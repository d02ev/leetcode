#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;

class MyHashMap1 {
    private:
        const static long unsigned bucket_size = 1000001;
        int bucket[bucket_size];

    public:
        MyHashMap1() {
            fill(bucket, bucket + bucket_size, -1);
        }

        void put(int key, int value) {
            bucket[key] = value;
        }

        int get(int key) {
            return bucket[key];
        }

        void remove(int key) {
            bucket[key] = -1;
        }
};

class MyHashMap {
    private:
        const static long unsigned bucket_size = 1000;
        vector<list<pair<int, int>>> bucket;

        int hashF(int key) { return key % bucket_size; }

        list<pair<int, int>>::iterator searchKey(int index, int key) {
            return find_if(bucket[index].begin(), bucket[index].end(), [key](pair<int, int> keyValuePair) { return keyValuePair.first == key; });
        }
        
    public:
        MyHashMap() {
            bucket.resize(bucket_size);
        }

        void put(int key, int value) {
            int index = hashF(key);
            list<pair<int, int>>::iterator itr = searchKey(index, key);

            if (itr == bucket[index].end()) {
                bucket[index].push_front(make_pair(key, value));
                return;
            }

            itr -> second = value;
            return;
        }

        int get(int key) {
            int index = hashF(key);
            list<pair<int, int>>::iterator itr = searchKey(index, key);

            if (itr == bucket[index].end()) {
                return -1;
            }

            return itr -> second;
        }

        void remove(int key) {
            int index = hashF(key);
            list<pair<int, int>>::iterator itr = searchKey(index, key);

            if (itr == bucket[index].end()) {
                return;
            }

            bucket[index].erase(itr);
            return;
        }
};

int main(int argc, char** argv) {
    MyHashMap *hash_map = new MyHashMap();

    hash_map -> put(1, 1);
    hash_map -> put(2, 2);

    cout << hash_map -> get(1) << endl;
    cout << hash_map -> get(3) << endl;

    hash_map -> put(2, 1);

    cout << hash_map -> get(2) << endl;

    hash_map -> remove(2);

    cout << hash_map -> get(2) << endl;

    return 0;
}