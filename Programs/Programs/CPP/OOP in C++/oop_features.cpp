#include <iostream>
#include <string>

class Animal {
    protected:
        std::string name;
        int age;

    public:
        // Constructor
        Animal(std::string n, int a) : name(n), age(a) {}

        // Virtual function
        virtual void makeSound() = 0;
};

class Dog : public Animal {
    private:
        std::string breed;

    public:
        // Constructor
        Dog(std::string n, int a, std::string b) : Animal(n, a), breed(b) {}

        // Inherited function
        void makeSound() {
            std::cout << "Woof!" << std::endl;
        }

        // Encapsulation methods
        void setName(std::string n) {
            name = n;
        }

        std::string getName() {
            return name;
        }

        void setAge(int a) {
            age = a;
        }

        int getAge() {
            return age;
        }

        void setBreed(std::string b) {
            breed = b;
        }

        std::string getBreed() {
            return breed;
        }
};

class Cat : public Animal {
    private:
        std::string color;

    public:
        // Constructor
        Cat(std::string n, int a, std::string c) : Animal(n, a), color(c) {}

        // Inherited function
        void makeSound() {
            std::cout << "Meow!" << std::endl;
        }

        // Polymorphism method
        void playWith(Animal& otherAnimal) {
            std::cout << name << " is playing with " << otherAnimal.name << std::endl;
        }
};

class Person {
    private:
        std::string name;

    public:
        // Constructor
        Person(std::string n) : name(n) {}

        // Composition relationship
        void adoptAnimal(Animal& animal) {
            std::cout << name << " adopted " << animal.getName() << std::endl;
        }
};

int main() {
    Dog myDog("Fido", 5, "Labrador");
    Cat myCat("Whiskers", 3, "Grey");
    Person myPerson("John");

    myDog.makeSound();
    myCat.makeSound();
    myCat.playWith(myDog);
    myPerson.adoptAnimal(myDog);

    return 0;
}
