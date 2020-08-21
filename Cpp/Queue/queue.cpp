//Queue implementation
#include <iostream>
#include<memory>
#include<string>
#include <vector> 
using namespace std;
//Linked list


//Node class
template <typename T>
class Node{
public:
        explicit Node(T val) : node_val(val){}
        
        ~Node() {}
        
        std::shared_ptr<Node<T>> getNext(){
            return node_next;
        }
        
        void setNext(std::shared_ptr<Node<T>>& next){
            node_next = next;
        }
        
        void delNext(){
            node_next = NULL;
        }
        
        
        T getValue(){
            return node_val;
        }
        
private:
	T node_val;
	std::shared_ptr<Node<T>> node_next;
};

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

template <typename T>
class LinkedList{
    private:
        shared_ptr<Node<T>> head;
        shared_ptr<Node<T>> tail;
        int count;
        
        bool addLast(shared_ptr<Node<T>>& node){
            count ++;
            if(count == 1){
                head  = node;
                tail = head;
                return true;
            }
            
            shared_ptr<Node<T>> temp = tail;
            tail->setNext(node);
            tail = node;
            return true;
        }
        
        bool popFirst(){
            head = head->getNext();
            count --;
            return true;
        }
        
    public:
        LinkedList():count(0){}
        ~LinkedList(){};
        
        
        bool addLast(T val){
            auto new_node = make_shared<Node<T>>(val);
            return addLast(new_node);
        }
        
        T * popFront(){
            T *valptr;
            if(isEmpty()){
                valptr = nullptr;
            } else {
                auto val = head->getValue();
                valptr = &val;
                popFirst();
            }
            return valptr;
        }
        
        bool isEmpty(){
            if(count < 1){
                return true;
            }
            return false;
        }
        
        void print(){
            cout<<"BACK| <-";
            auto temp=head;
            while(temp != nullptr){
            cout<<temp->getValue()<<"<-";
            temp = temp->getNext();
            }
            cout<<"| FRONT";
            cout<<endl;
        
        };
        
};


template <typename T>  //Queue class for LL Implementation
class QueueLinkedList{
    public:

        LinkedList<T> LL;
        bool enqueue(T val){
            return LL.addLast(val);
        }
        
        T * dequeue(){
            //auto value = LL.popFront();
            return LL.popFront();
        }
        
        bool isEmpty(){
            return LL.isEmpty();
        }
        void print(){
            LL.print();
        }
        
};

template <typename T> //Queue class for array implementation
class QueueArray{
    private:
        T read = 0,write = 0; //index
        T arr[5];
        int maxLen = 5;
        int mod(int a, int b) { return (a % b + b) % b; }
        
    public:
        bool enqueue(T val){
            if(isFull()){
                return false;
            }
            arr[write] = val;
            write = (write+1) % maxLen;
            
            return true;
        }
        
        T * dequeue(){
            T *valptr;
            if(isEmpty()){
                valptr = nullptr;
            } else {
                auto val = arr[read];
                read = mod((read+1),maxLen);
                valptr = &val;
            }

            return valptr;
        }
        
        bool isEmpty(){
            return (read == write);
        }
        
        bool isFull(){
            return (mod(read -1,maxLen) == mod(write,maxLen));
        }
        
        void print(){
            int i = read;
            while(i != write){
                cout<<arr[i]<<"<-";
                i = mod((i+1) , maxLen);
            }
            cout<<endl;
        }
        
};


template <typename T> //Queue class for array implementation
class QueueDynamicArray{
    private:

        vector<T> arr;
        
    public:
        bool enqueue(T val){
            arr.insert(arr.end(),val);
            return true;
        }
        
        T * dequeue(){
            T *valptr;
            if(isEmpty()){
                valptr = nullptr;
            } else {
                T val =  *arr.begin();
                valptr = &val;
                arr.erase(arr.begin());
            }

            return valptr;
        }
        
        bool isEmpty(){
            return arr.empty();
        }
        
        void print(){
            for(auto i = arr.begin(); i != arr.end(); i++){
                cout << *i << "<-";
            }
            cout<<endl;
        }
        
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






