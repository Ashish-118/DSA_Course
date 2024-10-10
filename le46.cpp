#include <iostream>
using namespace std;

class hero
{
    int age, salary;

public:
    char *name;
    hero(int age, int salary)
    {
        this->age = age;
        this->salary = salary;
    }
    // hero(hero &obj)
    // {
    //     cout << "copy constructor called" << endl;
    //     this->age = obj.age;
    //     this->salary = obj.salary;
    // }

    hero(hero &temp) // copy constructor
    {
        char *ch = new char[strlen(temp.name) + 1];
        // strcpy(ch, temp.name);
        this->name = ch;
        cout << "Copy constructor called" << endl;
        this->age = temp.age;
        this->salary = temp.salary;
    }
    void setname(char name[])
    {
        strcpy(this->name, name);
    }
    void display()
    {
        cout << "Name is " << name << " The age is " << age << " and the salary is " << salary << endl;
    }
};
int main()
{

    hero obj1(14, 2342);
    char name[] = {'a', 's', 'h', 'i', 's', 'h'};
    obj1.name = name;
    obj1.name[1] = 'H'; // for understanding the shallow copy  means when we change something in the  obj1  and it reflects that change in the obj2
                        //  which is copy constructor   is shallow copy.
    obj1.setname(name);
    obj1.display();

    hero obj2(obj1);
    obj2.display();

    return 0;
}