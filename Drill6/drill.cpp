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
template<typename T> const T& S<T>::get()const
{
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
//
template<typename T> void read_val(T& v){
    cin >> v;
}
template<typename T> istream& operator>>(istream& is, S<T>& tt)
{
    T v;
    cin >> v;
    if(!is)
    {
        return is;
    }
    tt=v;
    return is;
}

template<class T> istream& operator>>(istream& is, vector<T>& a){
    char n1;
    char n2;
    T temp;
    vector<T> v_temp;
    is >> n1;
    if(!is){
        return is;
    }
    if(n1!='{')
    {
        is.clear();
        error("{ expected! ");
        return is;
    }
    while (cin>>temp>>n2 && n2==',')
    {
        v_temp.push_back(temp);
    }
    if(n2!='}'){
        is.clear();
        error("} expected! ");
        return is;
    }
    v_temp.push_back(temp);
    a = v_temp;
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
    cout << endl;
    sINT = 15;
    sCHAR = '$';
    sDOUBLE = 107.1;
    sSTRING = "DEstring";
    sVECTOR = {11,12,13,14,15};

    cout << "sINT " << sINT.get() << endl;
    cout << "sCHAR " << sCHAR.get() << endl;
    cout << "sDOUBLE " << sDOUBLE.get() << endl;    
    cout << "sSTRING " << sSTRING.get() << endl;
    cout << "sVECTOR " << sVECTOR.get() << endl;

    cout<<"sINT: ";
    read_val(sINT);
    cout<<"sCHAR: ";
    read_val(sCHAR);  
    cout<<"sDOUBLE: ";
    read_val(sDOUBLE);
    cout<<"sSTRING: ";
    read_val(sSTRING);
    cout<<"sVECTOR :";
    read_val(sVECTOR);

    cout << "sINT " << sINT.get() << endl;
    cout << "sCHAR " << sCHAR.get() << endl;
    cout << "sDOUBLE " << sDOUBLE.get() << endl;    
    cout << "sSTRING " << sSTRING.get() << endl;
    cout << "sVECTOR " << sVECTOR.get() << endl;


}