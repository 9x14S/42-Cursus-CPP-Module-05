#include <iostream>

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cerr << "GradeTooHighException test" << std::endl;
	try
	{
		Bureaucrat a = Bureaucrat("Too High", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cerr << "GradeTooLowException test" << std::endl;
	try
	{
		Bureaucrat b = Bureaucrat("Too Low", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat c = Bureaucrat("Increment-Decrement Test", 5);

	std::cerr << "Increment test" << std::endl;
	for (; c.getGrade() != 1; c.incrementGrade())
		std::cout << c << std::endl;

	std::cerr << "Decrement test" << std::endl;
	for (; c.getGrade() != 10; c.decrementGrade())
		std::cout << c << std::endl;
	return (0);
}
