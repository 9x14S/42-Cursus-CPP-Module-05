#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form( void )
	: _name(""), _signed(false), _sign_requirement(1), _exec_requirement(1)
{
	// Same as comment below
}

Form::Form( Form &that )
	: _name(that.getName()), _signed(that.getSignedStatus()),
	  _sign_requirement(that.getSignRequirement()),
	  _exec_requirement(that.getExecRequirement())
{
	// No exception throwing because `that` should have been sanitized during
	// creation and due to the members being private
}

Form::Form( std::string name, int sign_requirement, int exec_requirement )
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

// getters
const std::string	&Form::getName( void )
{
	return _name;
}

bool				Form::getSignedStatus( void )
{
	return _signed;
}

int					Form::getSignRequirement( void )
{
	return _sign_requirement;
}

int					Form::getExecRequirement( void )
{
	return _exec_requirement;
}

// setters
void Form::setSignedStatus( bool signedness )
{
	this->_signed = signedness;
}

void Form::beSigned( Bureaucrat &b )
{
	if (b.getGrade() > this->getSignRequirement())
		throw Form::GradeTooLowException();
	this->setSignedStatus(true);
}

std::ostream	&operator<<( std::ostream &output, Form &f )
{
	output
		<< f.getName() << ", "
		<< f.getSignedStatus() << ", "
		<< f.getSignRequirement() << ", "
		<< f.getExecRequirement()
		<< std::endl;;
	return output;
}
