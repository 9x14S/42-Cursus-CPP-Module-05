#include <cstdlib>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

#define ROBOTOMY_SIGN_REQUIREMENT 72
#define ROBOTOMY_EXEC_REQUIREMENT 45

// Orthodox Canonical Form
RobotomyRequestForm::RobotomyRequestForm( void )
	:	AForm(
			"RobotomyRequestForm",
			ROBOTOMY_SIGN_REQUIREMENT,
			ROBOTOMY_EXEC_REQUIREMENT),
		_target("RobotomyRequestForm")
{}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &that )
	:	AForm(
			that.getName(),
			ROBOTOMY_SIGN_REQUIREMENT,
			ROBOTOMY_EXEC_REQUIREMENT),
		_target(that._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm & that)
{
	AForm::operator=(that);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{}

// Main stuff
RobotomyRequestForm::RobotomyRequestForm( std::string target )
	:	AForm(
			target,
			ROBOTOMY_SIGN_REQUIREMENT,
			ROBOTOMY_EXEC_REQUIREMENT),
		_target(target)
{}

void RobotomyRequestForm::execute( const Bureaucrat &b ) const
{
	if (b.getGrade() > this->getExecRequirement())
		throw AForm::GradeTooLowException();
	else if (!this->getSignedStatus())
		throw AForm::FormNotSignedException();
	if (rand() % 2)
		std::cout << "\"" << this->_target << "\" robotomized successfully!" << std::endl;
	else
		std::cout << "\"" << this->_target << "\" robotomization failed!" << std::endl;
}
