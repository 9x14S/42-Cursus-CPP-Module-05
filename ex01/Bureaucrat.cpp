#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Orthodox Canonical Form
Bureaucrat::Bureaucrat( void ) : _name("None"), _grade(150) {}

Bureaucrat::Bureaucrat( std::string name, int grade )
	: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat &that )
	: _name(that._name), _grade(that._grade) {}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &that)
{
	if (this != &that)
		this->_grade = that._grade;
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {}
// End Orthodox Canonical Form

const std::string &Bureaucrat::getName( void ) const
{
	return _name;
}

int	Bureaucrat::getGrade( void ) const
{
	return _grade;
}

void	Bureaucrat::incrementGrade( void )
{
	if (getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if (getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm( Form &form )
{
	try
	{
		form.beSigned( *this );
		std::cout << "\"" << this->getName() << "\""
			<< " signed \"" << form.getName() << "\"" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\"" << this->getName() << "\""
			<< " couldn't sign \"" << form.getName() << "\""
			<< " because \"" << e.what() << "\"" << std::endl;
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "(bureaucrat) grade is too low!!!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "(bureaucrat) grade is too high!!!";
}

std::ostream &operator<<( std::ostream &output, const Bureaucrat &that )
{
	output << that.getName() << ", bureaucrat grade " << that.getGrade() << ".";
	return output;
}
