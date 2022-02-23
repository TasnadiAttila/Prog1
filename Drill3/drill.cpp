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
    B1 b_object;
    b_object.vf();
    b_object.f();

    D1 d_object;
    d_object.vf();
    
    B1& b_ref_obj = d_object;
    b_ref_obj.vf();
    b_ref_obj.f();


    return 0;
}