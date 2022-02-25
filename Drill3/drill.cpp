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

//6
class D2 : public D1{
    public:
        void pvf(){
            cout << "D2:pvf()" << endl;
        }
};

//7
class B2{
    public:
        virtual void pvf() = 0;
            
};
class D21 : public B2{
    public:
        string overrideTEXT;
        void pvf() override { 
            cout << overrideTEXT << endl;
        }
    
};
class D22 : public B2 {
    public:
        int dataMember;
        void pvf(){
            cout << dataMember << endl;
        }
        void f(B2& R){
            R.pvf();
        }
};

int main(){
    //1
    B1 b_object;
    b_object.vf();
    b_object.f();

    cout << " " << endl;
    //2
    D1 d_object;
    d_object.vf();
    //4
    d_object.f();
    
    cout << " " << endl;
    //3
    B1& b_ref_obj = d_object;
    b_ref_obj.vf();
    b_ref_obj.f();
    
    cout << " " << endl;
    //5
    b_object.pvf();//its from B1
    d_object.pvf();//The class D has its own pvf
    b_ref_obj.pvf();//B ref is refers to D

    cout << " " << endl;
    //6 
    //ahonnan származik azokat írja kivéve a pvf()-nél mert abból van sajátja
    D2 d2_object;
    d2_object.f();
    d2_object.vf();
    d2_object.pvf();

    cout << " " << endl;
    //7
    D21 d21_obj;
    d21_obj.overrideTEXT = "Over ride text";
    D22 d22_obj;
    d22_obj.dataMember = 8;

    d22_obj.f(d21_obj);
    d22_obj.f(d22_obj);





    return 0;
}