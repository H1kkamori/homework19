#include <iostream>
#include <vector>

class Animal
{
private:
    virtual void Voice() const
    {
        std::cout << "Some generic animal sound" << std::endl;
    }
public:
    virtual ~Animal() = default;

    void MakeVoice() const 
    {
        Voice();
    }
};

class Dog : public Animal
{
private:
    void Voice() const override 
    {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal 
{
private:
    void Voice() const override 
    {
        std::cout << "Meow!" << std::endl;
    }
};

class Frog : public Animal 
{
private:
    void Voice() const override 
    {
        std::cout << "Ribbit!" << std::endl;
    }
};

int main() 
{
    std::vector<Animal*> animals;

    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Frog());

    for (const auto& animal : animals) 
    {
        animal->MakeVoice();
    }

    for (const auto& animal : animals) 
    {
        delete animal;
    }

    return 0;
}