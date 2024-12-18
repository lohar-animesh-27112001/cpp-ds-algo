#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    string gender;
    int age;
public:
    Person(int age) : age(age) {}
    void set_name(const string& name) {
        this->name = name;
    }
    void set_gender(const string& gender) {
        this->gender = gender;
    }
    void display() const {
        cout << "Name: " << name << ", Gender: " << gender << ", Age: " << age << endl;
    }
};

class Male : public Person {
protected:
    string profession;
public:
    Male(const string& name, const string& gender, int age) : Person(age) {
        this->set_name(name);
        this->set_gender(gender);
    }
    void set_profession(const string& profession) {
        this->profession = profession;
    }
    void display() const {
        Person::display();
        cout << "Profession: " << profession << endl;
    }
};

int main() {
    Male person1("Animesh", "Male", 20);
    person1.set_profession("S/W Engineer");
    person1.set_name("Animesh Lohar");
    person1.display();
    return 0;
}
