#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

#define PARDON_SIGN_REQUIREMENT 72
#define PARDON_EXEC_REQUIREMENT 45

// Orthodox Canonical Form
PresidentialPardonForm::PresidentialPardonForm( void )
	:	AForm(
			"PresidentialPardonForm",
			PARDON_SIGN_REQUIREMENT,
			PARDON_EXEC_REQUIREMENT),
		_target("PresidentialPardonForm")
{}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &that )
	:	AForm(
			that.getName(),
			PARDON_SIGN_REQUIREMENT,
			PARDON_EXEC_REQUIREMENT),
		_target(that._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm & that)
{
	AForm::operator=(that);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{}

// Main stuff
PresidentialPardonForm::PresidentialPardonForm( std::string target )
	:	AForm(
			target,
			PARDON_SIGN_REQUIREMENT,
			PARDON_EXEC_REQUIREMENT),
		_target(target)
{}

void PresidentialPardonForm::execute( const Bureaucrat &b ) const
{
	if (b.getGrade() > this->getExecRequirement())
		throw AForm::GradeTooLowException();
	else if (!this->getSignedStatus())
		throw AForm::FormNotSignedException();
	std::cout << "\"" << this->_target << "\" has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
