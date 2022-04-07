#include "../std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>
#include <numeric>
//1005
using namespace  Numeric_lib;


//4
void SQUAREROOT(){
    int val;
    cin >> val;
    if(val < 0){
        cout << "no square root" << endl;
    } 
    else{
        cout << val << " - " << sqrt(val) << endl;
    }
}

int main(){
    
    //1
    cout << "Char: " << sizeof(char) << endl;
    cout << "Short: " << sizeof(short) << endl;
    cout << "Int: " << sizeof(int) << endl;
    cout << "Long: " << sizeof(long) << endl;
    cout << "Float: " << sizeof(float) << endl;
    cout << "Double: " << sizeof(double) << endl;
    cout << "Int*: " << sizeof(int*) << endl;
    cout << "Double*: " << sizeof(double*) << endl;

    //2
    cout << endl;
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);//int typed two dimensional
    Matrix<int,3> e(10,10,10);

    cout << "a: " << sizeof(a) << endl;
    cout << "b: " << sizeof(b) << endl;
    cout << "c: " << sizeof(c) << endl;
    cout << "d: " << sizeof(d) << endl;
    cout << "e: " << sizeof(e) << endl;

    //3-elemnts in 
    cout << endl;
    cout << "Elements in a: " << a.size() << endl;
    cout << "Elements in b: " << b.size() << endl;
    cout << "Elements in c: " << c.size() << endl;
    cout << "Elements in d: " << d.size() << endl;//10*10
    cout << "Elements in e: " << e.size() << endl;//10*10*10

    //4
    cout << endl;
    cout << "Enter values to check ther root: " << endl;
    for(int i = 0;i<4;++i){
        SQUAREROOT();
    }

    //5
    cout << endl;
    cout << "Enter 10 doubles: " << endl;
    Matrix<double> five(10);
    double value;
    for(int i = 0;i<10;++i){
        cin >> value;
        five[i] = value;
    }
    cout << endl;
    for (int i = 0; i < five.size(); i++)
    {
        cout << five[i] << endl;
    }
    //6 - 1007
    int m,n;
    cout << "Dimensons: " << endl;
    cin >> m >> n;
    Matrix<double,2> six(m,n);
    for(int i = 0;i<six.dim1();++i){
        for(int j = 0;j<six.dim2();++j){
            cout << six(i,j) << " ";
        }
    }
    
    //7
    cout << endl;
    cout << "Enter 10 doubles to get their sum: " << endl;
    Matrix<complex<double>> seven (10);
    double temp;
    double sum;
    for(int i = 0;i<seven.size();++i){
        cin >> temp;
        seven[i] = temp;
        sum += temp;
    }
    cout << "Sum of values: " << sum << endl;
    //8
    cout << endl;
    cout << "Enter six values: " << endl;
    Matrix<int,2> ms(2,3);
    for(int i = 0;i< ms.dim1();++i){
        for(int j = 0;j<ms.dim2();++j){
            cin >> ms[i][j];
        }
    }
    cout << endl;
    cout << ms << endl;
    
}