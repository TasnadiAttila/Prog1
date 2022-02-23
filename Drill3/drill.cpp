#include "std_lib_facilities.h"
class B1{
    public:
        virtual void vf(){
            cout << "B1::vf()" << endl;
        };
        void f(){
            cout << "B1::f()" << endl;
        };

};
int main(){
    B1 b;
    b.vf();
    b.f();




    return 0;
}