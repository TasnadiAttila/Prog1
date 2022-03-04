#include "std_lib_facilities.h"

struct Person
{
    private: 
        string First_Name;
        string Secound_Name;
        int Age;

    public:
        Person(){
            First_Name = " ";
            Secound_Name = " ";
            Age = 0;
        };

        Person(string fN, string sN, int a){

            string Tiltott = ";:\"'[]*&^%$#@!";
        
            for (int i = 0; i < fN.size(); i++)
            {
                for (int j = 0; j < Tiltott.size(); j++)
                {
                    if (fN[i]==Tiltott[j])
                    {
                        error("Bad character in Fisrt_name!");
                    }
                }           
            }
            for (int i = 0; i < sN.size(); i++)
            {
                for (int j = 0; j < Tiltott.size(); j++)
                {
                    if (sN[i]==Tiltott[j])
                    {
                        error("Bad character in Secound_name!");
                    }
                }           
            }
            if(!(a>0 && a<150)){
                error("Age is not in range");
            }
            First_Name = fN;
            Secound_Name = sN; 
            Age = a;
            
        };  
        
        string name() const{
            return First_Name + " " + Secound_Name;
        }
        int age() const{
            return Age;
        }

};  

ostream& operator<<(ostream& out, Person& PersoN)
{
    out << PersoN.name() << " " << PersoN.age() << endl;
    return out;
    
}
istream& operator>>(istream& in, Person& PersoN) 
{
    string FName;
    string SName;
    int Age;
    in >> FName >> SName >> Age;
    PersoN = Person(FName,SName,Age);//felülír
    return in;
}
//https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm
 
int main(){
    Person person1("Goofy","Floofy",63);
    cout << person1;

    
    Person person2;
    int szamol = 0;
    cout << "Hany ember: ";
    cin >> szamol;
    int szamol2 = 0;
    vector<Person> emberek;
    while(cin>>person2)
    {
        emberek.push_back(person2);
        szamol2++;
        if(szamol2 == szamol) break;
    }
    cout << endl;
    for (int i = 0; i < emberek.size(); i++)
    {
        cout << emberek[i];
    }
    


    return 0;
}