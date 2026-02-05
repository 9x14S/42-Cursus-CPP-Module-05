#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	Form		a = Form("Test form", 5, 6);
	Bureaucrat	b = Bureaucrat("Can sign and exec", 5);
	Bureaucrat	c = Bureaucrat("Can just exec", 6);
	Bureaucrat	d = Bureaucrat("Can't sign or exec", 7);
	std::cout << a << std::endl;

	d.signForm(a);
	c.signForm(a);
	b.signForm(a);
	return (0);
}
