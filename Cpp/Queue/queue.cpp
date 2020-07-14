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
        
        void addFirst(shared_ptr<Node<T>>& node){
            shared_ptr<Node<T>> temp = head;
            head = node;
            node->setNext(temp);
            count ++;
            if(count == 1){
                tail = head;
            }
        }
        
        void popLast(){
            shared_ptr<Node<T>> temp = head;
            while(temp->getNext()->getNext() != nullptr){
                temp = temp->getNext();
            }
            
            temp->delNext();
            tail = temp;
        }
        
    public:
        LinkedList():count(0){}
        ~LinkedList(){};
        
        void addFirst(T val){
            auto new_node = make_shared<Node<T>>(val);
            addFirst(new_node);
        }
        
        T pop(){
            auto pop_val = tail->getValue();
            popLast();
            return pop_val;
        }
        
        void print(){
            auto temp=head;
            while(temp != nullptr){
            cout<<temp->getValue()<<"->";
            temp = temp->getNext();
            }
            cout<<"NULL";
            cout<<endl;
        
        };
        
};

template <typename T>
class QueueLL{
    public:
        LinkedList<T> LL;
        
        void enqueue(T val){
            LL.addFirst(val);
        }
        
        T dequeue(){
            auto value = LL.pop();
            return value;
            
        }
        
        void print(){
            LL.print();
        }
        
};


int main() {
    
    QueueLL<string> QL;
    QL.enqueue("node1");
    QL.enqueue("node2");
    QL.enqueue("node3");
    QL.print();
    cout<<QL.dequeue()<<endl;
    QL.print();

	//code
	return 0;
}






