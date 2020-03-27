// pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <limits>
#include <random>

struct Person
{
public:
    Person() = default;
    Person(std::string name, int age)
        :m_name(name), m_age(age)
    {
    }
public:
    std::string m_name;
    int m_age = 0;
};

double pointerAddition(double* ptr);
Person* newPerson();

int main()
{
    double x = 7.666;
    double* xPointer = &x;

    //This is the address of xPointer
    std::cout << xPointer << '\n';

    //Defrefence of xPointer give the number that is assigned to x
    std::cout << *xPointer << '\n';

    *xPointer = pointerAddition(xPointer);

    std::cout << *xPointer << '\n';

    Person frankHorrigan("Frank Horrigan", 42);
    Person* pointToFrankHorrigan = &frankHorrigan;

    Person* personPointer = new Person("NamelessBrown", 101);
    
    std::cout << "Name: " << personPointer->m_name << " Age: " << personPointer->m_age << "\n\n";

    Person* personPointerTestFunction = newPerson();


    std::cout << "Name: " << personPointerTestFunction->m_name << " Age: " << personPointerTestFunction->m_age << "\n\n"; 

    /* ARRAYS not ARRAIES */
    constexpr unsigned size = 99;
    Person people[size];

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(1, 30);

    int numberOfNamelesses = 1;
    for (auto peeps : people)
    {
        peeps.m_name = personPointer->m_name;
        peeps.m_age = distribution(rng);

        std::cout << numberOfNamelesses++ << " Name: " << peeps.m_name << " Age: " << peeps.m_age << '\n';
    }


    delete personPointerTestFunction;
    delete personPointer;
}

double pointerAddition(double* ptr)
{
    double y = *ptr;

    y += *ptr;

    return y;
}

Person* newPerson()
{
    std::string newName;
    int newAge = 0;

    std::cout << "Enter a new name:\t";
    std::getline(std::cin, newName);

    std::cout << "Enter an age!\t";
    std::cin >> newAge;

    while (std::cin.fail())
    {
        std::cout << "Try again!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin >> newAge;
    }


    return new Person(newName, newAge);
}