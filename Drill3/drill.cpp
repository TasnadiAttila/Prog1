#include "std_lib_facilities.h"
class B1{
    public:
        void vf(){
            cout << "B1::vf()" << endl;
        };
        void f(){
            cout << "B1::f()" << endl;
        };

};
class D1 : public B1{
    public:
        void vf() {
            cout << "D1::vf()" << endl;
        };
};
int main(){
    B1 b;
    b.vf();
    b.f();
    D1 d;
    d.vf();
    



    return 0;
}