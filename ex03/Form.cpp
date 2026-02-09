#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form( void )
	: _name(""), _signed(false), _sign_requirement(1), _exec_requirement(1)
{
	// Same as comment below
}

Form::Form( const Form &that )
	: _name(that.getName()), _signed(that.getSignedStatus()),
	  _sign_requirement(that.getSignRequirement()),
	  _exec_requirement(that.getExecRequirement())
{
	// No exception throwing because `that` should have been sanitized during
	// creation and due to the members being private
}

Form::Form( const std::string name, int sign_requirement, int exec_requirement )
	: _name(name), _signed(false),
	  _sign_requirement(sign_requirement),
	  _exec_requirement(exec_requirement)
{
	if (this->getSignRequirement() > 150)
		throw Form::GradeTooLowException();
	if (this->getSignRequirement() < 1)
		throw Form::GradeTooHighException();

	if (this->getExecRequirement() > 150)
		throw Form::GradeTooLowException();
	if (this->getExecRequirement() < 1)
		throw Form::GradeTooHighException();
}

Form::~Form( void ) {}

Form &Form::operator=( const Form &that )
{
	if (this != &that)
		this->_signed = that.getSignedStatus();
	return *this;
}

// getters
const std::string	&Form::getName( void ) const
{
	return _name;
}

bool				Form::getSignedStatus( void ) const
{
	return _signed;
}

int					Form::getSignRequirement( void ) const
{
	return _sign_requirement;
}

int					Form::getExecRequirement( void ) const
{
	return _exec_requirement;
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
	return "grade too low!";
}

const char *Form::GradeTooHighException::what( void ) const throw()
{
	return "grade too high!";
}

const char *Form::FormNotSignedException::what( void ) const throw()
{
	return "Form is not signed!";
}

void Form::beSigned( Bureaucrat &b )
{
	if (b.getGrade() > this->getSignRequirement())
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<( std::ostream &output, const Form &f )
{
	output
		<< "Name      : " << f.getName() << std::endl
		<< "Signed    : " << f.getSignedStatus() << std::endl
		<< "Grade required for Signing  : " << f.getSignRequirement() << std::endl
		<< "Grade required for Executing: " << f.getExecRequirement() << std::endl;
	return output;
}
