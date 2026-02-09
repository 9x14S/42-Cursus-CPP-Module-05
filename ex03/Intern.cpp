#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

// Orthodox Canonical Form
Intern::Intern( void )
{}

Intern::Intern( const Intern &that )
{}

Intern &Intern::operator=( const Intern & that)
{
	return *this;
}

Intern::~Intern( void )
{}

// Subject requirement
AForm *Intern::makeForm( const std::string form_type, std::string form_target ) const
{
}
