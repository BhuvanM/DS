//Queue implementation
#include <iostream>
#include<memory>
#include<string>
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
        
        void addLast(shared_ptr<Node<T>>& node){
            count ++;
            if(count == 1){
                head  = node;
                tail = head;
                return;
            }
            
            shared_ptr<Node<T>> temp = tail;
            tail->setNext(node);
            tail = node;
        }
        
        void popFirst(){
            head = head->getNext();
            count --;
        }
        
    public:
        LinkedList():count(0){}
        ~LinkedList(){};
        
        
        void addLast(T val){
            auto new_node = make_shared<Node<T>>(val);
            addLast(new_node);
        }
        
        T popFront(){
            if(isEmpty()){
                return "Emmpty queue";
            }
            auto val = head->getValue();
            popFirst();
            return val;
        }
        
        int isEmpty(){
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
class QueueLL{
    public:

        LinkedList<T> LL;
        void enqueue(T val){
               LL.addLast(val);
        }
        
        T dequeue(){
            auto value = LL.popFront();
            return value;
        }
        
        int isEmpty(){
            return LL.isEmpty();
        }
        void print(){
            LL.print();
        }
        
};

template <typename T> //Queue class for array implementation
class QueueArr{
    private:
        T read = 0,write = 0; //index
        T arr[5]; //Fixed size was mentioned as req
        int maxLen = 5;
        //int count;
        
    public:
        void enqueue(T val){ //YET TO BE FIXED
            cout<<read<<write;
            if(isFull()){
                cout<<"Queue is Full";
                return;
            }
            arr[write] = val;
            if((write+1) % maxLen == read-1){
                cout<<"FULL";
                return;
            }
            write = (write+1) % maxLen;
        }
        
        T dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty";
                return -1;
            }
            auto value = arr[read];
            read = (read+1) % maxLen;
            //count --;
            return value;
        }
        
        int isEmpty(){
            return (read == write);
        }
        
        int isFull(){
            //if((read%maxLen)-1 == write)
            return ((read%maxLen)-2 == write%maxLen);
        }
        void print(){
            int i = read;
            cout<<"read"<<read<<"write"<<write;
            while(i != write){
                cout<<arr[i]<<"<-";
                i = (i+1) % maxLen;
            }
            cout<<endl;
        }
        
};


int main() {
    
    // QueueLL<string> QL;
    // QL.enqueue("node1");
    // QL.enqueue("node2");
    // QL.enqueue("node3");
    // QL.print();
    // cout<<QL.dequeue()<<endl;
    // QL.dequeue();
    // QL.dequeue();
    // cout<<QL.dequeue()<<endl;
    // QL.print();
    
    QueueArr<int> QR; //limitation, string cannot be used in this for now
    QR.enqueue(1);
    QR.enqueue(2);
    QR.enqueue(3);
    QR.enqueue(4);
    QR.enqueue(5);
    QR.enqueue(6);
    //QR.enqueue(7);
    //QR.dequeue();
    QR.print();
    

	//code
	return 0;
}






