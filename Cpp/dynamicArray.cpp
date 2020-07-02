#include <iostream>
#include<iterator> // for iterators 
#include<vector> // for vectors 
#include <memory.h>
using namespace std;


    
    class array
    {
        private:
        
        int* arr = new int[2];
        int l = 0;
        int cap = 2;

        public:
        
        int size(){
            return l;
        }
        
        int capacity(){
            return cap;
        }
        
        bool is_empty(){
            return (l==0)?true:false;
        }
        
        int at(int index){
            return arr[index];
        }
        
        int push(int elem){
            if(l == cap){
                this->resize(cap*2);
            }
            
            arr[l] = elem;
            l ++;
            
        }
        
        int insert(int index, int elem){
            if(l == cap){
                this->resize(cap*2);
            }
            
            for(int i=l-1;i>=index;i--){
                arr[i+1] = arr[i];
            }
            
            arr[index] = elem;
            l++;
            
        }
        
        int prepend(int elem){
            if(l == cap){
                this->resize(cap*2);
            }
            
             for(int i=l-1;i>=0;i--){
                arr[i+1] = arr[i];
            }
            arr[0] = elem;
            l++;
            
        }
        
        int pop(){
            int popElem = arr[l-1];
            arr[l-1] = 0;
            l--;
            if(l*4 < cap)
            {
                int temp_cap = cap;
                cap = l;
                this->resize(temp_cap/2);
            }
            return popElem;
        }
        
        int deleteElem(int index){
            
            this->removeElem(arr[index]);
        }
        
        int removeElem(int elem){
            
            int* temp_arr = new int[cap];
            int tmpCnt = 0;
            for(int i=0;i<l;i++){
                if(arr[i] != elem){
                    temp_arr[tmpCnt] = arr[i];
                    tmpCnt ++;
                }
            }
            l = tmpCnt+1;
            delete(arr);
            arr = temp_arr;
            l--;
            if(l*4 < cap)
            {
                int temp_cap = cap;
                cap = l;
                this->resize(cap/2);
            }
        }
        
        int find(int elem){
            for(int i=0;i<l;i++){
                if(arr[i] == elem){
                    return i;
                }
            }
            return -1;
        }
        
        int resize(int newCap){
            int* temp_arr = new int[newCap];
            
            memcpy(temp_arr,arr,cap * sizeof(int));
            
            delete(arr);
            arr = temp_arr;
            cap = newCap;
            
        }
    };

int main() {
    
    
    array obj;
    
    for(int i=0;i<obj.size();i++){
        cout<<obj.at(i)<<'\t';
    }
    cout<<'\n';
    

    for(int i=0;i<10;i++){
        obj.push(i);
    }
    cout<<'\n'<<obj.capacity()<<'\n';
    cout<<'\n'<<obj.size()<<'\n';
    
    for(int i=0;i<obj.size();i++){
        cout<<obj.at(i)<<',';
    }
    cout<<'\n';
    
    obj.insert(5,2);
    for(int i=0;i<obj.size();i++){
        cout<<obj.at(i)<<',';
    }
    cout<<'\n';
    
    obj.prepend(2);
    
    for(int i=0;i<obj.size();i++){
        cout<<obj.at(i)<<',';
    }
    cout<<'\n';
    
    cout<<obj.pop();
    cout<<'\n'<<obj.size()<<'\n';
    cout<<'\n';
    for(int i=0;i<obj.size();i++){
        cout<<obj.at(i)<<',';
    }
    cout<<'\n';
    
    obj.deleteElem(8);
    
    for(int i=0;i<obj.size();i++){
        cout<<obj.at(i)<<',';
    }
    cout<<'\n';
    
    obj.removeElem(2);
    for(int i=0;i<obj.size();i++){
        cout<<obj.at(i)<<',';
    }
    cout<<'\n';
    
    for(int i=0;i<4;i++){
        obj.pop();
    }
    
    cout<<'\n'<<obj.size();
    cout<<'\n'<<obj.capacity();
    
    
    
    

    return 0;
}
