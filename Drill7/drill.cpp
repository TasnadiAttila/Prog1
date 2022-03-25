#include "../std_lib_facilities.h"
//812
template<typename Iter1, typename Iter2>
Iter2 MyCopy(Iter1 f1, Iter1 e1, Iter2 f2){
    while (f1 != e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}

	return f2;
}

//iterator- elemre mutató pointer 
int main()
{
    array <int,10> MyArray = {0,1,2,3,4,5,6,7,8,9};
    vector<int> MyVector = {0,1,2,3,4,5,6,7,8,9};
    list<int> MyList = {0,1,2,3,4,5,6,7,8,9};

    //copy array to array and increase value by 2
    array <int,10> MyArray2;
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
 
    

    MyCopy(MyArray.begin(),MyArray.end(),MyVector2.begin());
    MyCopy(MyList.begin(),MyList.end(),MyArray2.begin());

    auto position = find(MyVector2.begin(),MyVector2.end(),3);//most egy memory address
    if(position == MyVector2.end())
    {
        cout << "Nincs benne" << endl;
    }
    else
    {
        for(int i = 0;i<MyVector2.size();++i)
        {
            if(MyVector2[i]== *position){//ha az a memória címet megtalálja akkor ahha
                cout << "Benne van" << " a " << i << ". helyen" << endl;
            }
        }
    }
    
    auto position2 = find(MyList2.begin(),MyList2.end(),27);//most egy memory address
    if(position2 == MyList2.end())
    {
        cout << "Nincs benne" << endl;
    }
    else
    {
        for(int i = 0;i<MyVector2.size();++i)
        {
            if(MyVector2[i]== *position2){//ha az a memória címet megtalálja akkor ahha
                cout << "Benne van" << " " << i << ". helyen" << endl;
            }
        }
    }

}

    //for(int i = 0; i < 10;++i){
    //    cout << MyArray[i] << " " << MyVector2[i] << endl;
   // }
    

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
    
