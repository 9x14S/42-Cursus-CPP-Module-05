#include <ctime>
#include <cstdlib>

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	Intern random_intern;

	// Succeed
	Bureaucrat a("All-doer", 1);
	try
	{
		Form *pardon = NULL;
		pardon = random_intern.makeForm("presidential pardon", "Random Criminal");
		a.signForm(*pardon);
		a.executeForm(*pardon);
		delete pardon;
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern couldn't create a presidential pardon form because \""
			<< e.what() << "\"" << std::endl;
	}
	try
	{
		Form *robotomy = NULL;
		robotomy = random_intern.makeForm("robotomy request", "Roomba");
		a.signForm(*robotomy);
		a.executeForm(*robotomy);
		delete robotomy;
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern couldn't create a robotomy request form because \""
			<< e.what() << "\"" << std::endl;
	}
	try
	{
		Form *shrubbery = NULL;
		shrubbery = random_intern.makeForm("shrubbery creation", "Tree");
		a.signForm(*shrubbery);
		a.executeForm(*shrubbery);
		delete shrubbery;
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern couldn't create a shrubbery creation form because \""
			<< e.what() << "\"" << std::endl;
	}

	// Fail
	Bureaucrat b("Nothing-doer", 150);
	try
	{
		Form *pardon = NULL;
		pardon = random_intern.makeForm("presidential pardon", "Random Criminal");
		b.signForm(*pardon);
		b.executeForm(*pardon);
		delete pardon;
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern couldn't create a presidential pardon form because \""
			<< e.what() << "\"" << std::endl;
	}
	try
	{
		Form *robotomy = NULL;
		robotomy = random_intern.makeForm("robotomy request", "Roomba");
		b.signForm(*robotomy);
		b.executeForm(*robotomy);
		delete robotomy;
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern couldn't create a robotomy request form because \""
			<< e.what() << "\"" << std::endl;
	}
	try
	{
		Form *shrubbery = NULL;
		shrubbery = random_intern.makeForm("shrubbery creation", "Tree");
		b.signForm(*shrubbery);
		b.executeForm(*shrubbery);
		delete shrubbery;
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern couldn't create a shrubbery creation form because \""
			<< e.what() << "\"" << std::endl;
	}

	// Fail on creating form
	Form *nonexistent = random_intern.makeForm("non-existent form", "None");
	(void)nonexistent;
	return (0);
}
