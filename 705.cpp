#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class MyHashSet {
    private:
        const unsigned long static bucket_size = 1000001;
        int bucket[bucket_size];

    public:
        MyHashSet() {
            fill(bucket, bucket + bucket_size, -1);
        }

        void add(int key) {
            bucket[key] = key;
        }

        bool contains(int key) {
            if (bucket[key] < 0)
                return false;

            return true;
        }

        void remove(int key) {
            bucket[key] = -1;
        }
};

class MyHashSet1 {
    private:
        const unsigned long static bucket_size = 1000001;
        int bucket[bucket_size];

    public:
        MyHashSet1() {
            fill(bucket, bucket + bucket_size, 0);
        }

        void add(int key) {
            bucket[key] = 1;
        }

        bool contains(int key) {
            return bucket[key];
        }

        void remove(int key) {
            bucket[key] = 0;
        }
};

class MyHashSet2 {
    private:
        const unsigned long static bucket_size = 1000;
        vector<list<int>> bucket;

        int hashF(int key) { return key % bucket_size; }

        list<int>::iterator search(int index, int key) {
            return find(begin(bucket[index]), end(bucket[index]), key);
        }

    public:
        MyHashSet2() {
            bucket.resize(bucket_size);
        }

        void add(int key) {
            int index = hashF(key);

            if (search(index, key) != bucket[index].end())
                return;

            bucket[index].push_front(key); 
        }

        bool contains(int key) {
            int index = hashF(key);

            if (search(index, key) == bucket[index].end())
                return false;

            return true;
        }

        void remove(int key) {
            int index = hashF(key); 

            if (search(index, key) == bucket[index].end())
                return;

            bucket[index].remove(key);
        }

};

int main(int argc, char** argv) {
    MyHashSet2* hash_set2 = new MyHashSet2();

    hash_set2 -> add(1);
    hash_set2 -> add(2);

    cout << boolalpha;

    cout << hash_set2 -> contains(1) << endl;
    cout << hash_set2 -> contains(3) << endl;

    hash_set2 -> add(2);

    cout << hash_set2 -> contains(2) << endl;

    hash_set2 -> remove(2);

    cout << hash_set2 -> contains(2) << endl;

    return 0;
}