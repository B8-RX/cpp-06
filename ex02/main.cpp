#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base*	generate(void) {
	const int	i = std::rand() % 3;
	
	if (i == 0)
		return (new A());
	if (i == 1)
		return (new B()); 
	return (new C()); 
}

static void	identify(Base* p) {
	if (!p)
		return;
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

static void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p); 
		std::cout << "A\n";
		return ;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	} catch (...) {}
}

int main(void) {
	
	std::srand(std::time(NULL));
	Base* p = generate();
	
	identify(p);
	identify(*p);
	delete p;
	return (0);
}
