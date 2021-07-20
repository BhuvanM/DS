#include <iostream>
using namespace std;

//Hash table implementation using linear probing

/*
Limitation:
The hash function is mod x. Hence only int type can be used for keys. This can be extended for other datatype keys if need by improving the hash function
*/

template <typename K, typename V>
class hashNode{
    public:
        hashNode(K key,V value) : key{key},value{value} 
        {}

        K getKey(){
            return key;
        }
        V getValue(){
            return value;
        }
        void setKey(K k){
            key = k;
        }
        void setValue(V v){
            value = v;
        }

    private:
        K key;
        V value;
};

template<typename K>
class hashFunction{
    public:
         int getHash(K key,int m){ //m cardinality
            return key % m;
        }
};

template <typename K, typename V> 
class hashTable{

    public:
        hashTable(int l) :  capacity{l}{
            size = 0;
            arr = new hashNode<K,V>*[capacity];
            for(int i=0 ; i < capacity ; i++) {arr[i] = NULL;}
            empty = new hashNode<K,V>(-1, -1); 
        };
        
        void insertNode(K key,V value){

            hashNode<K,V> *temp = new hashNode<K,V>(key,value);

            int hashIndex = hashFunc.getHash(key,capacity);
            int i=0;
            while(arr[hashIndex] != NULL && arr[hashIndex]->getKey() != key && arr[hashIndex]->getKey() != -1){
                if(i>capacity){
                    cerr<<"Table is FULL";
                    return;
                }
                i++;
                hashIndex++;
                hashIndex %=capacity; 
            }

            if(arr[hashIndex] == NULL || arr[hashIndex]->getKey() == -1){
                size ++;
                arr[hashIndex] = temp;
            }

        }

        void removeNode(K key){
            int hashIndex = hashFunc.getHash(key,capacity);
        
            while(arr[hashIndex] != NULL){

                if(arr[hashIndex]->getKey() == key){

                    hashNode<K,V> *emptyNode = empty; 
                    arr[hashIndex] = emptyNode;
                    size --;
                    return ;
                }

                hashIndex++; 
                hashIndex %= capacity; 
            }

            return;
        }

        V get(K key){
            int hashIndex = hashFunc.getHash(key,capacity);
            int i = 0;

            while(arr[hashIndex] != NULL){

                if(i>capacity){
                    cerr<<"\n Key not found \n";
                    return -1;
                }

                if(arr[hashIndex]->getKey() == key){
                    return arr[hashIndex]->getValue();
                }

                i++;
                hashIndex ++; 
                hashIndex %= capacity;
            }

            cerr<<"\n Key not found \n";
            return -1;
        }

        bool exists(K key){
            V value = get(key);
            if(value == -1){
                return false;
            } else {
                return true;
            }
        }

        void display() 
        { 
            cout<<"\n \n ";
            for(int i=0 ; i<capacity ; i++) { 
                if(arr[i] != NULL && arr[i]->getKey() != -1) 
                cout << "key = " << arr[i]->getKey()<<"  value = "<< arr[i]->getValue() << endl; 
            } 
            cout<<"\n \n";
        }      

    private:
        int size,capacity;
        hashNode<K,V> **arr; //array of nodes
        hashNode<K,V> *empty; //single node
        hashFunction<K> hashFunc;

};


int main() {

    int maxTableCapacity = 10;
    hashTable<int,float> h(maxTableCapacity); 

    h.insertNode(18,1.1);
    h.insertNode(41,10);
    h.insertNode(22,20);
    h.insertNode(32,30);
    h.insertNode(44,40);
    h.insertNode(59,50);
    h.insertNode(79,60);
    h.insertNode(13,80);
    h.display();
    h.removeNode(13);
    h.display();
    cout<<h.get(32)<<'\n';
     cout<<"Does exist : "<<h.exists(32)<<'\n';
    return 0;
}