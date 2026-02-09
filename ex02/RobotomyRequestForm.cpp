#include <cstdlib>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "Form.hpp"

#define ROBOTOMY_SIGN_REQUIREMENT 72
#define ROBOTOMY_EXEC_REQUIREMENT 45

// Orthodox Canonical Form
RobotomyRequestForm::RobotomyRequestForm( void )
	:	Form(
			"RobotomyRequestForm",
			ROBOTOMY_SIGN_REQUIREMENT,
			ROBOTOMY_EXEC_REQUIREMENT),
		_target("RobotomyRequestForm")
{}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &that )
	:	Form(
			that.getName(),
			ROBOTOMY_SIGN_REQUIREMENT,
			ROBOTOMY_EXEC_REQUIREMENT),
		_target(that._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm & that)
{
	Form::operator=(that);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{}

// Main stuff
RobotomyRequestForm::RobotomyRequestForm( std::string target )
	:	Form(
			target,
			ROBOTOMY_SIGN_REQUIREMENT,
			ROBOTOMY_EXEC_REQUIREMENT),
		_target(target)
{}

void RobotomyRequestForm::execute( const Bureaucrat &b ) const
{
	if (!this->getSignedStatus())
		throw Form::FormNotSignedException();
	if (b.getGrade() > this->getExecRequirement())
		throw Form::GradeTooLowException();
	std::cout << "<Drilling noises>" << std::endl;
	if (rand() % 2)
		std::cout << "\"" << this->_target << "\" robotomized successfully!" << std::endl;
	else
		std::cout << "\"" << this->_target << "\" robotomization failed!" << std::endl;
}
