#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

// Orthodox Canonical Form
Intern::Intern( void )
{}

Intern::Intern( const Intern &that )
{
	(void)that;
}

Intern &Intern::operator=( const Intern & that)
{
	(void)that;
	return *this;
}

Intern::~Intern( void )
{}

AForm *Intern::_createShrubbery(std::string target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::_createPardon(std::string target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::_createRobotomy(std::string target) const
{
	return new RobotomyRequestForm(target);
}

// Subject requirement
AForm *Intern::makeForm( const std::string form_type, std::string form_target ) const
{
	const std::string _functionNames[3] = {
		"shrubbery creation",
		"presidential pardon",
		"robotomy request",
	};

	_function_ptr _functionPointers[3] = {
		&Intern::_createShrubbery,
		&Intern::_createPardon,
		&Intern::_createRobotomy,
	};

	for (size_t i = 0; i < 3; i++)
		if (form_type == _functionNames[i])
		{
			std::cout << "Intern creating \"" << form_type << "\"..." << std::endl;
			return (this->*_functionPointers[i])(form_target);
		}
	std::cerr << "Intern failed in creating \"" << form_type << "\"!" << std::endl;
	return NULL;
}
