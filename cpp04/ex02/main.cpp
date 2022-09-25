#include  "Dog.hpp"
#include  "Cat.hpp"

int main()
{
	{
	const AAnimal* d_animal = new Dog();
	const AAnimal* c_animal = new Cat();
	std::cout << std::endl;
		std::cout << "d_animal type: " << d_animal->getType() << std::endl;
		std::cout << "c_animal type: " << c_animal->getType() << std::endl;
	std::cout << std::endl;
		d_animal->makeSound();
		c_animal->makeSound(); 

	std::cout << std::endl;
	delete d_animal;
	delete c_animal;
	}
}