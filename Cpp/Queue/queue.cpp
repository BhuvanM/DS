//Queue implementation
#include <iostream>
#include<memory>
#include<string>
#include <vector> 
using namespace std;
//Linked list


/*Node class definition*/
template <typename T>
class Node{
public:
        explicit Node(T val) : node_val(val){}
        
        ~Node() {}
        
        std::shared_ptr<Node<T>> getNext();
        
        void setNext(std::shared_ptr<Node<T>>& next);
        
        void delNext();
        T getValue();
        
private:
	T node_val;
	std::shared_ptr<Node<T>> node_next;
};


template <typename T>
std::shared_ptr<Node<T>> Node<T>::getNext(){
     return node_next;
}

template <typename T>
void Node<T>::setNext(std::shared_ptr<Node<T>>& next){
    node_next = next;
}

template <typename T>
void Node<T>::delNext(){
    node_next = NULL;
}

template <typename T>
T Node<T>::getValue(){
    return node_val;
}


//print function
template<typename T>
void print(shared_ptr<Node<T>>& node){
    auto temp=node;
    while(temp != nullptr){
        cout<<temp->getValue()<<"->";
        temp = temp->getNext();
    }
    cout<<"NULL";
    cout<<endl;
};



/*Linked list class definition*/
template <typename T>
class LinkedList{
    private:
        shared_ptr<Node<T>> head = NULL;
        shared_ptr<Node<T>> tail = NULL;
        
        bool addLast(shared_ptr<Node<T>>& node);
        bool popFirst();
        
    public:
        LinkedList(){}
        ~LinkedList(){};
        
        
        bool addLast(T val);
        
        T * popFront();
        
        bool isEmpty();
        
        void print();
        
};

template <typename T>
bool LinkedList<T>::addLast(shared_ptr<Node<T>>& node){
            if(head == NULL){
                head  = node;
                tail = head;
                return true;
        }
            
            shared_ptr<Node<T>> temp = tail;
            tail->setNext(node);
            tail = node;
            return true;
};

template <typename T>
bool LinkedList<T>:: popFirst(){
    head = head->getNext();
    return true;
};

template <typename T>
bool LinkedList<T>:: addLast(T val){
    auto new_node = make_shared<Node<T>>(val);
    return addLast(new_node);
};

template <typename T>
T* LinkedList<T>::popFront(){
    T *valptr;
    if(isEmpty()){
        valptr = nullptr;
    } else {
        auto val = head->getValue();
        valptr = &val;
        popFirst();
    }
    return valptr;
};

template <typename T>
bool LinkedList<T>::isEmpty(){
    if(head == NULL){
        return true;
    }
    return false;
};

template <typename T>
void LinkedList<T>::print(){
    cout<<"BACK| <-";
    auto temp=head;
    while(temp != nullptr){
        cout<<temp->getValue()<<"<-";
        temp = temp->getNext();
    }
    cout<<"| FRONT";
    cout<<endl;
};



/*Queue class using LL Implementation*/
template <typename T>
class QueueLinkedList{
    public:

        LinkedList<T> LL;
        bool enqueue(T val);
        
        T * dequeue();
        
        bool isEmpty();

        void print();
        
};

template <typename T>
bool QueueLinkedList<T>::enqueue(T val){
            return LL.addLast(val);
};

template <typename T>
T* QueueLinkedList<T>::dequeue(){
    return LL.popFront();
}

template <typename T>
bool QueueLinkedList<T>::isEmpty(){
    return LL.isEmpty();
}

template <typename T>
void QueueLinkedList<T>::print(){
    LL.print();
}



/*Queue class using array implementation*/
template <typename T> 
class QueueArray{
    private:
        T read = 0,write = 0; //index
        T arr[5];
        int maxLen = 5;
        int mod(int a, int b) { return (a % b + b) % b; }
        
    public:
        bool enqueue(T val);
        
        T * dequeue();
        
        bool isEmpty();
        
        bool isFull();
        
        void print();
};

template <typename T>
bool QueueArray<T>::enqueue(T val){
    if(isFull()){
        return false;
    }
    arr[write] = val;
    write = (write+1) % maxLen;
    
    return true;
};

template <typename T>
T* QueueArray<T>::dequeue(){
    T *valptr;
    if(isEmpty()){
        valptr = nullptr;
    } else {
        auto val = arr[read];
        read = mod((read+1),maxLen);
        valptr = &val;
    }

    return valptr;
};

template <typename T>
bool QueueArray<T>::isEmpty(){
    return (read == write);
};

template <typename T>
bool QueueArray<T>::isFull(){
    return (mod(read -1,maxLen) == mod(write,maxLen));
}

template <typename T>
void QueueArray<T>::print(){
    int i = read;
    while(i != write){
        cout<<arr[i]<<"<-";
        i = mod((i+1) , maxLen);
    }
    cout<<endl;
}



/*Queue class using dynamic array implementation*/
template <typename T>
class QueueDynamicArray{
    private:

        vector<T> arr;
        
    public:
        bool enqueue(T val);
        
        T * dequeue();
        
        bool isEmpty();
        
        void print();
        
};

template <typename T>
bool QueueDynamicArray<T>::enqueue(T val){
            arr.insert(arr.end(),val);
            return true;
};

template <typename T>
T* QueueDynamicArray<T>::dequeue(){
    T *valptr;
    if(isEmpty()){
        valptr = nullptr;
    } else {
        T val =  *arr.begin();
        valptr = &val;
        arr.erase(arr.begin());
    }

    return valptr;
};

template <typename T>
bool QueueDynamicArray<T>::isEmpty(){
    return arr.empty();
};

template <typename T>
void QueueDynamicArray<T>::print(){
    for(auto i = arr.begin(); i != arr.end(); i++){
        cout << *i << "<-";
    }
    cout<<endl;
};

int main() {
    
    //Queue using linked list
    QueueLinkedList<string> QL;
    QL.enqueue("node1");
    QL.enqueue("node2");
    QL.enqueue("node3");
    QL.print();
    QL.dequeue();
    QL.dequeue();
    QL.dequeue();
    QL.print();
    if(QL.dequeue() == nullptr){
        cout<<"Linked list Queue is empty \n";
    }
    QL.print();

    //Circular queue using fixed array
    QueueArray<int> QR; //limitation, string cannot be used in this for now
    QR.enqueue(0);
    QR.enqueue(1);
    QR.enqueue(2);
    QR.print();
    //QR.dequeue();
    cout<<*QR.dequeue()<<'\n';
    cout<<*QR.dequeue()<<'\n';
    cout<<*QR.dequeue()<<'\n';
    if(QR.dequeue() == nullptr){
        cout<<" Array Queue is empty \n";
    }
    QR.print();
    
    //Queue using dynamic array
    QueueDynamicArray<int> QDR;
    QDR.enqueue(1);
    QDR.enqueue(2);
    QDR.enqueue(3);
    QDR.enqueue(4);
    QDR.enqueue(5);
    QDR.print();
    QDR.dequeue();
    cout<<*QDR.dequeue()<<'\n';
    cout<<*QDR.dequeue()<<'\n';
    cout<<*QDR.dequeue()<<'\n';
    cout<<*QDR.dequeue()<<'\n';

    if(QR.dequeue() == nullptr){
        cout<<" Dynamic Array Queue is empty \n";
    }
    QDR.print();
    return 0;
}


