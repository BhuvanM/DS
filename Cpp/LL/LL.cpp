#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next = NULL;
};



int isEmpty(struct node **headRef){
	if(*headRef == NULL){
	        return true;
	 }
	    return false;
};

int value_at(struct node **headRef,int index){
	    if(*headRef == NULL){
	        cout<<"Error ! List is empty";
	        return 0;
	    } else {
	        struct node *temp;
	        temp=*headRef;
	        for(int i=0;i<index;i++){
	            temp = temp->next;
	        }
	        return temp->data;
	    }
	    
	}
	
void push_front(struct node **headRef,int item,int &size){
	    struct node *newNode;
	    newNode = (struct node*)malloc(sizeof(struct node));
	    newNode->data = item;
	    
	    if(*headRef == NULL){
	        *headRef = newNode;
	        size++;
	        return;
	    } else {
	        
	        newNode->next = *headRef;
	        *headRef = newNode;
	        size++;
	        return;
	    }
	    
	}
	
int pop_front(struct node **headRef, int &size){
      struct node *temp;
      temp = *headRef;
	  int data = temp->data;
	  *headRef = temp->next;
	   temp->next = NULL;
	   free(temp);
	   size--;
	   return data;
	}
	
int push_back(struct node **headRef,int item, int &size){
    struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = item;
    
	
    if(*headRef == NULL){
        *headRef = newNode;
        size++;
        return 0;
    } else{
        struct node *temp;
        temp = *headRef;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
        return 0;
    }
    return 0;
    
}

int pop_back(struct node **headRef,int &size){
    if(*headRef ==NULL){
        return 0;
    } else {
        int data;
        struct node *temp;
        struct node *delTemp;
        temp = *headRef;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delTemp = temp->next;
        data = temp->next->data;
        temp->next = NULL;
        free(delTemp);
        size --;
        return data;
    }
    
}

int front(struct node **headRef){
    if(*headRef == NULL){
        cout<<"List is empty"<<'\n';
        return 0;
    } else {
        return (*headRef)->data;
    }
}

int back(struct node **headRef){
    if(*headRef == NULL){
        cout<<"List is empty"<<'\n';
        return 0;
    } else {
        struct node *temp;
        temp = *headRef;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp->data;
    }
}

int insert(struct node **headRef, int index, int item,int &size){
        struct node *newNode;
	    newNode = (struct node*)malloc(sizeof(struct node));
	    newNode->data = item;
	    
        if(*headRef == NULL){
            if(index == 0){
                *headRef = newNode;
                size++;
            } else {
                cout<<"Error ! List is empty";
	            return 0;
            }
	    } else {
	        if(index ==0){
	            push_front(&*headRef,item,size);
	            return 0;
	        } 
	        struct node *temp;
	        temp=*headRef;
	        for(int i=0;i<index-1;i++){
	            temp = temp->next;
	        }
	        
	        
	        newNode->next = temp->next;
	        temp->next= newNode;
	        size ++;
	        return 0;
            
	    }
}

int erase(struct node **headRef,int index, int &size){

	
	if(*headRef == NULL){
	    cout<<"The list is empty "<<'\n';
	    return 0;
	} else {
	    if(index == 0){
	        pop_front(&*headRef,size);
	        return 0;
	    }
	    struct node *temp;
	    struct node *delTemp;
	    temp = *headRef;
	    
	    for(int i=0;i<index-1;i++){
	        temp = temp->next;
	    }
	    
	    delTemp = temp->next;
	    temp->next = temp->next->next;
	    free(delTemp);
	    size --;
	    return 0;
	}
}

int value_n_from_end(struct node **headRef,int index,int &size){
    
    if(*headRef == NULL){
	    cout<<"The list is empty "<<'\n';
	    return 0;
	} else {
	    struct node *temp;
        temp = *headRef;
        for(int i=0;i<(size-1)-index;i++){
            temp = temp->next;
        }
        return temp->data;
	}
}

int reverse(struct node **headRef){
    if(*headRef == NULL){
	    cout<<"The list is empty "<<'\n';
	    return 0;
	} else if((*headRef)->next == NULL){
	    return 0;
	}
	else{
	    struct node *temp;
	    struct node *tempNxt;
	    struct node *revTemp1 = *headRef;
	    struct node *revTemp2 = *headRef;
	    
	    temp = *headRef;
	    while(revTemp2 != NULL){
	        if(revTemp2 == *headRef){ //First element
	            revTemp2 = (*headRef)->next;
	            (*headRef)->next = NULL;

	        } else {
	            temp = revTemp2;
	            tempNxt = revTemp2->next;
	            revTemp2->next = revTemp1;
	            revTemp1 = temp;
	            if(tempNxt == 0){ //End of list
	               *headRef = revTemp2;
	                revTemp2 = NULL;
	            } else {
	                revTemp2 = tempNxt;
	            }
	        }
	    }
	    
	    return 0;
	}
}

int remove_value(struct node **headRef,int item,int &size){
    if(*headRef == NULL){
	    cout<<"The list is empty "<<'\n';
	    return 0;
	}
	else {
	    if((*headRef)->data == item){
	        pop_front(&*headRef,size);
	        return 0;
	    }
	    struct node *temp;
	    struct node *delTemp;
	    temp = *headRef;
	    while(temp->next!=NULL){
	        if(temp->next->data == item){
	            delTemp = temp->next;
	            if(temp->next->next == NULL){
	                temp->next = NULL;
	                
	            } else {
	                temp->next = temp->next->next;
	            }
	            
	            free(delTemp);
	            size --;
	            return 0;
	        }
	        temp = temp->next;
	    }
	    return 0;
	}
}

int display(struct node **headRef){
    if(*headRef == NULL){
	    cout<<"The list is empty "<<'\n';
	    return 0;
	} else if((*headRef)->next == NULL){
	    cout<<(*headRef)->data<<'\n';
	}
	else{
	    struct node *temp;
        temp = *headRef;
        cout<<'\n';
        
        while(temp->next!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<temp->data;
        cout<<'\n';
        return 0;
	}
    
    
}
int main() {
	struct node *head = NULL;
	int size = 0;

//TEST
    display(&head);
    push_front(&head,1,size);
    push_front(&head,2,size);
    push_front(&head,3,size);
    push_front(&head,4,size);
    display(&head);
    cout<<"SIZE"<<size<<'\n';
    display(&head);
    push_back(&head,5,size);
    display(&head);
    cout<<pop_back(&head,size)<<'\n';
    display(&head);
    cout<<front(&head)<<'\n';
    cout<<back(&head)<<'\n';
    push_front(&head,6,size);
    push_front(&head,7,size);
    display(&head);
    insert(&head,1,8,size);
    display(&head);
    erase(&head,0,size);
    display(&head);
    cout<<"SIZE"<<size<<'\n';
    cout<<value_n_from_end(&head,0,size);
    reverse(&head); 
    display(&head);
    remove_value(&head,4,size); 
    display(&head);
	return 0;
}

