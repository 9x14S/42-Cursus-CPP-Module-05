#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm( void )
	: _name(""), _signed(false), _sign_requirement(1), _exec_requirement(1)
{
	// Same as comment below
}

AForm::AForm( const AForm &that )
	: _name(that.getName()), _signed(that.getSignedStatus()),
	  _sign_requirement(that.getSignRequirement()),
	  _exec_requirement(that.getExecRequirement())
{
	// No exception throwing because `that` should have been sanitized during
	// creation and due to the members being private
}

AForm::AForm( const std::string name, int sign_requirement, int exec_requirement )
	: _name(name), _signed(false),
	  _sign_requirement(sign_requirement),
	  _exec_requirement(exec_requirement)
{
	if (this->getSignRequirement() > 150)
		throw AForm::GradeTooLowException();
	if (this->getSignRequirement() < 1)
		throw AForm::GradeTooHighException();

	if (this->getExecRequirement() > 150)
		throw AForm::GradeTooLowException();
	if (this->getExecRequirement() < 1)
		throw AForm::GradeTooHighException();
}

AForm::~AForm( void ) {}

AForm &AForm::operator=( const AForm &that )
{
	if (this != &that)
		this->_signed = that.getSignedStatus();
	return *this;
}

// getters
const std::string	&AForm::getName( void ) const
{
	return _name;
}

bool				AForm::getSignedStatus( void ) const
{
	return _signed;
}

int					AForm::getSignRequirement( void ) const
{
	return _sign_requirement;
}

int					AForm::getExecRequirement( void ) const
{
	return _exec_requirement;
}

const char *AForm::GradeTooLowException::what( void ) const throw()
{
	return "grade too low!";
}

const char *AForm::GradeTooHighException::what( void ) const throw()
{
	return "grade too high!";
}

const char *AForm::FormNotSignedException::what( void ) const throw()
{
	return "Form is not signed!";
}

void AForm::beSigned( Bureaucrat &b )
{
	if (b.getGrade() > this->getSignRequirement())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<( std::ostream &output, const AForm &f )
{
	output
		<< "Name      : " << f.getName() << std::endl
		<< "Signed    : " << f.getSignedStatus() << std::endl
		<< "Grade required for Signing  : " << f.getSignRequirement() << std::endl
		<< "Grade required for Executing: " << f.getExecRequirement() << std::endl;
	return output;
}
