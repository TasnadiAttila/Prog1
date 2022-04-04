#include "../std_lib_facilities.h"

//
// Comparator function to sort pairs
// according to second value
bool cmp(pair<string, int>& a,
         pair<string, int>& b)
{
    return a.second < b.second;
}
  
// Function to sort the map according
// to value in a (key-value) pairs
void sort(map<string, int>& M)
{
  
    // Declare vector of pairs
    vector<pair<string, int> > A;
  
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        A.push_back(it);
    }
  
    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);
  
    // Print the sorted value
    for (auto& it : A) {
  
        cout << it.first << ' '
             << it.second << endl;
    }
}
//

//function to read
void READ(map<string,int>& MyMap){
    string s;
    int i;
    cin >> s >> i;
    MyMap.insert(pair<string,int>(s,i));
}
ostream& operator<<(ostream& output, const map<string,int>& MyMap){
    for (const auto& p : MyMap)
        cout << p.first << ": " << p.second << '\n';

    return output;
}

int main(){
    //inserting part
    map<string,int> msi = {
        {"egy",1},
        {"ketto",2},
        {"harom",3},
        {"negy",4},
        {"ot",5},
        {"hat",6},
        {"het",7},
        {"nyolc",8},
        {"kilenc",9},
        {"tiz",10}
    };
   
        
    sort(msi);
    cout << endl;
    /* így is végig lehet rajta menni
    for (const auto& p : msi)
        cout << p.first << ": " << p.second << '\n';
    */

    //erasing part
    //-> "az osztály tagjainak pointeren keresztüli elérése"
    map<string,int>::iterator it;

    it=msi.find("nyolc");
    for(it=msi.begin(); it!=msi.end();++it){
        cout << it->first << " => " << it->second << endl;
    }

    /*
    for(int i=0;i<10;++i)
    {
        READ(msi);
    }
    */
    cout << endl;
    cout << msi;

    cout << endl;
    int sum;
    for(const auto& p : msi){
        sum+=p.second;
    }
    cout << sum << endl;

    //9.next

}