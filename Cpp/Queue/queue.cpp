//Queue implementation
#include <iostream>
#include<memory>
using namespace std;
//Linked list



//Node class
template <typename T>
class Node{
public:
        explicit Node(T val) : node_val(val){}
        
        Node() {}
        
        std::shared_ptr<Node<T>> getNext(){
            return node_next;
        }
        
        void setNext(std::shared_ptr<Node<T>>& next){
            node_next = next;
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
        cout<<temp->node_val<<endl;
        temp = temp->getNext();
    }
};




int main() {
	//code
	return 0;
}
