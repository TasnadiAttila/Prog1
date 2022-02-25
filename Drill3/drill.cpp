#include "std_lib_facilities.h"
//1
class B1{
    public:
        void vf(){
            cout << "B1::vf()" << endl;
        };
        void f(){
            cout << "B1::f()" << endl;
        };
        //5
        virtual void pvf(){
            cout << "B1::pvf()" << endl;
        }
};
//2
class D1 : public B1{
    public:
        void vf() {
            cout << "D1::vf()" << endl;
        };
        void f(){ //without defining f() for D1 in cout it shows B1::f1() bc it derives from there
          cout << "D1::f()" << endl;
        }
        //5
        virtual void pvf(){
            cout << "D1::pvf()" << endl;
        }
};
int main(){
    //1
    B1 b_object;
    b_object.vf();
    b_object.f();

    //2
    D1 d_object;
    d_object.vf();
    //4
    d_object.f();
    
    //3
    B1& b_ref_obj = d_object;
    b_ref_obj.vf();
    b_ref_obj.f();
    
    cout << " " << endl;
    //5
    b_object.pvf();//its from B1
    d_object.pvf();//The class D has its own pvf
    b_ref_obj.pvf();//B ref is refers to D



    return 0;
}