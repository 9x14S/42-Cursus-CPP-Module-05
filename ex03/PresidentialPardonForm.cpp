#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

#define PARDON_SIGN_REQUIREMENT 72
#define PARDON_EXEC_REQUIREMENT 45

// Orthodox Canonical Form
PresidentialPardonForm::PresidentialPardonForm( void )
	:	Form(
			"PresidentialPardonForm",
			PARDON_SIGN_REQUIREMENT,
			PARDON_EXEC_REQUIREMENT),
		_target("PresidentialPardonForm")
{}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &that )
	:	Form(
			that.getName(),
			PARDON_SIGN_REQUIREMENT,
			PARDON_EXEC_REQUIREMENT),
		_target(that._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm & that)
{
	Form::operator=(that);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{}

// Main stuff
PresidentialPardonForm::PresidentialPardonForm( std::string target )
	:	Form(
			target,
			PARDON_SIGN_REQUIREMENT,
			PARDON_EXEC_REQUIREMENT),
		_target(target)
{}

void PresidentialPardonForm::execute( const Bureaucrat &b ) const
{
	if (!this->getSignedStatus())
		throw Form::FormNotSignedException();
	if (b.getGrade() > this->getExecRequirement())
		throw Form::GradeTooLowException();
	std::cout << "\"" << this->_target << "\" has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
