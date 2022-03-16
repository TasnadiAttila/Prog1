#include "../std_lib_facilities.h"

template<typename T> struct S
{
    private:
        T val;
    public:
        S():val(T()){};//üres konstruktor, alapertelmezett dolog S<int> s_int();
        S(T a):val(a){};
        T& get();
        const T& get() const;
        void set(const T& a);//nemter vissza csak beallit
        T& operator=(const T&);

};
template<typename T>T& S<T>::get(){
    return val;
}
template<typename T>void S<T>::set(const T& a){
    val = a;
}
template<typename T> T& S<T>::operator=(const T& a){
    val = a;
    return val;
}
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){
    os << "{ ";
    for(int i = 0; i<a.size();++i){
        os << a[i];
        if(i<a.size()-1){
            os << ',';
        }
        os << ' ';
    }
    os << "}";
    return os;
}




int main(){
    //Incizialialas
    S<int> sINT(5);
    S<char> sCHAR('&');
    S<double> sDOUBLE(10.7);
    S<string> sSTRING("STRING");
    S<vector<int>> sVECTOR({1,2,3,4,5});

    cout << "sINT " << sINT.get() << endl;
    cout << "sCHAR " << sCHAR.get() << endl;
    cout << "sDOUBLE " << sDOUBLE.get() << endl;    
    cout << "sSTRING " << sSTRING.get() << endl;
    cout << "sVECTOR " << sVECTOR.get() << endl;

    //inicialialas 2
    cout << endl;
    cout << "SET" << endl;
    sINT.set(10);
    sCHAR.set('@');
    sDOUBLE.set(4.20);
    sSTRING.set("NEMstring");
    sVECTOR.set({6,7,8,9,10});

    cout << "sINT " << sINT.get() << endl;
    cout << "sCHAR " << sCHAR.get() << endl;
    cout << "sDOUBLE " << sDOUBLE.get() << endl;    
    cout << "sSTRING " << sSTRING.get() << endl;
    cout << "sVECTOR " << sVECTOR.get() << endl;

    //inicialialas 3
    sINT = 5;
    
    cout << sINT.get() << endl;
}