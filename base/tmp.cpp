#include <iostream>

using namespace std;
class Person{
public:
    Person(){}

    Person(string _name){
        name = _name;
        cout << name << " Constructor" << endl;
    }
    ~Person(){
        cout << name << " Destructor" << endl;
    }
private:
    string name;
};

int main(){
    Person p1("Park");
    Person tmp;
    Person p2("Kim");

    tmp = p1;
    p1 = p2;
    p2 = tmp;
    
    return 0;
}