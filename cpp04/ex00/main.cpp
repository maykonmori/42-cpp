#include  "Dog.hpp"
#include  "Cat.hpp"
#include  "WrongCat.hpp"

int main()
{
	{
	const Animal* meta = new Animal();
		const Animal* d_animal = new Dog();
		const Animal* c_animal = new Cat();
		std::cout << std::endl;

		std::cout << "meta type: " << meta->getType() << std::endl;
		std::cout << "d_animal type: " << d_animal->getType() << std::endl;
		std::cout << "c_animal type: " << c_animal->getType() << std::endl;
		std::cout << std::endl;

		meta->makeSound();
		d_animal->makeSound();
		c_animal->makeSound();

	std::cout << std::endl;
	delete meta;
	delete d_animal;
	delete c_animal;
	}
	std::cout << std::endl << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongCat();
		std::cout << std::endl;
	
		meta->makeSound();
		j->makeSound();
		std::cout << std::endl;

		delete j;
		delete meta;
	}
}