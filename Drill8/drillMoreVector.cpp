#include "../std_lib_facilities.h"

int main(){
    vector<double> vd;
    ifstream data_file("data2.txt");
    double d;
    while (data_file>>d)
    {
        vd.push_back(d);
    }

    vector<int> vi;
    for(const auto& p : vd){
        vi.push_back(p);
    }
    
    for(int i = 0;i<vd.size();++i){
        cout << vd[i] << " - " << vi[i] << endl;
    }

    double osszeg;
    for(int i = 0;i<vd.size();++i){
        osszeg+=vd[i];
    }
    int osszeg2;
    for(int i = 0;i<vd.size();++i){
        osszeg2+=vi[i];
    }
    cout << osszeg << endl;
    cout << osszeg-osszeg2 << endl;

    reverse(vd.begin(),vd.end());
    cout << endl;
       
    for(int i = 0;i<vd.size();++i){
        cout << vd[i] << " - " << vi[i] << endl;
    }

    double mean = osszeg/vd.size();
    vector<double> vd2;
    for(int i = 0;i<vd.size();++i){
        if(vd[i]<mean){
            vd2.push_back(i);
        }
    }


}