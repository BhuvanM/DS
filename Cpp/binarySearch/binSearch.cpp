#include <iostream>
using namespace std;


/*This code is for the binary search*/

/*Binary search on sorted array of integers, using recursion*/

template <typename T>
class application{
    /*Class for defining the application to which binary search is to be applied. Here its a simple sorted array*/
    public:

        application(T *arr):arr{arr}{}

        T getMidPoint(T min,T max){
            return min + (max - min) / 2;
        }

        string predicate(T lower,T upper, T key){ //Here: 

            if(arr[getMidPoint(lower,upper)] > key){
                return "lower";
            } else if(arr[getMidPoint(lower,upper)] < key){
                return "upper";
            } else if(arr[getMidPoint(lower,upper)] == key){
                return "equal";
            }
        } 

        T getUpperLimit(T lower,T upper){
            return  getMidPoint(lower,upper) - 1;
        }

        T getLowerLimit(T lower,T upper){
            return  getMidPoint(lower,upper) + 1;
        }

        T getMidPointValue(T lower,T upper){
            return arr[getMidPoint(lower,upper)];
        }

        private:
            T *arr;

};

template <typename T>
class binSearch{

    public: 

    binSearch(T *list): list{list}{
        p = new application<T>(list);
    } 
    
    T search(T key,T lower,T upper){
        
        if(!keyExists(lower, upper)){
            cout<<"!!!"<<lower<<"|"<<upper<<"@@";
            return -1;
        }
        
        if(p->predicate(lower,upper,key) == "lower"){

            search(key,lower,p->getUpperLimit(lower,upper));

        } else if(p->predicate(lower,upper,key) == "upper"){

            search(key,p->getLowerLimit(lower,upper),upper);

        } else if(p->predicate(lower,upper,key) == "equal"){

            return p->getMidPoint(lower,upper);
        }
    }

    bool keyExists(T lower,T upper){
        return (lower <= upper);
    }

    private:
        T *list;
        application<T> *p;
};



int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};

    binSearch<int> BS(arr);

    int arr1[] = {5,6,7,8,10000};
    binSearch<int> BS1(arr1);

    int lower = 0, upper = 13;
    cout<<BS.search(11,lower,upper)<<'\n';
    cout<<BS.search(3,lower,upper)<<'\n';
    cout<<BS.search(0,lower,upper)<<'\n';
    cout<<BS.search(13,lower,upper)<<'\n';

    cout<<BS1.search(10000,0,4)<<'\n';
    cout<<BS1.search(8,0,4)<<'\n';

    cout<<BS.search(10,lower,upper)<<'\n';

};