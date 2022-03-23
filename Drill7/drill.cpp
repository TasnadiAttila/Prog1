#include "../std_lib_facilities.h"

//iterator- elemre mutató pointer 
int main()
{
    int MyArray[10] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> MyVector = {0,1,2,3,4,5,6,7,8,9};
    list<int> MyList = {0,1,2,3,4,5,6,7,8,9};

    //copy array to array and increase value by 2
    int MyArray2[10];
    for(int i=0; i< 10;++i){
        MyArray2[i] = MyArray[i]+2;
    }

    //copy vector to vectory and increase value by 3
    vector<int> MyVector2 = MyVector;
    for(int i = 0; i<MyVector2.size();++i){
        MyVector2[i] = MyVector2[i]+3;
    }

    //copy list to list and increase value by 5 - vizsgan iteratoros - felette az
    list<int> MyList2 = MyList;
    for(auto &i : MyList2){
         i=i+5;
    }
 

/*
    for(int i = 0; i < 10;++i){
        cout << MyArray2[i] << endl;
    }


    for(int i = 0; i < MyVector2.size();++i){
        cout << MyVector2[i] << endl;
    }

   
    for(auto const& i : MyList){
        cout << i << " ";
    }
*/
    
}