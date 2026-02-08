#include <ctime>
#include <cstdlib>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	// Shrubbery tests
	ShrubberyCreationForm sform("Tree");
	Bureaucrat	a = Bureaucrat("Tree Signer", 1);
	Bureaucrat	b = Bureaucrat("Tree Executor", 1);
	Bureaucrat	c = Bureaucrat("Tree Fail Signer", 150);
	Bureaucrat	d = Bureaucrat("Tree Fail Executor", 150);

	a.signForm(sform);
	b.executeForm(sform);

	d.signForm(sform);
	c.executeForm(sform);

	std::cout << std::endl;

	// Robotomy tests
	RobotomyRequestForm rform("Roomba");
	Bureaucrat	e = Bureaucrat("Robotomy Signer", 1);
	Bureaucrat	f = Bureaucrat("Robotomy Executor", 1);
	Bureaucrat	g = Bureaucrat("Robotomy Fail Signer", 150);
	Bureaucrat	h = Bureaucrat("Robotomy Fail Executor", 150);

	e.signForm(rform);
	f.executeForm(rform);

	g.signForm(rform);
	h.executeForm(rform);

	std::cout << std::endl;

	// Pardon tests
	PresidentialPardonForm pform("Random Criminal");
	Bureaucrat	i = Bureaucrat("Pardon Signer", 1);
	Bureaucrat	j = Bureaucrat("Pardon Executor", 1);
	Bureaucrat	k = Bureaucrat("Pardon Fail Signer", 150);
	Bureaucrat	l = Bureaucrat("Pardon Fail Executor", 150);

	i.signForm(pform);
	j.executeForm(pform);

	k.signForm(pform);
	l.executeForm(pform);

	return (0);
}
