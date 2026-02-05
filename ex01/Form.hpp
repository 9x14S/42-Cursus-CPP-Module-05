#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Form
{
public:
	// Orthodox Canonical Form
	Form( void );
	Form( Form& that );
	Form& operator=( const Form& that );
	~Form( void );

	// Main constructor
	Form( std::string name, int sign_requirement, int exec_requirement);

	// Setters
	void	setSignedStatus( bool signedness );
	// Required methods
	void	beSigned( Bureaucrat &b );

	// Getters
	const std::string	&getName( void );
	bool				getSignedStatus( void );
	int					getSignRequirement( void );
	int					getExecRequirement( void );

	// Exception Members
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	const std::string	_name;
	bool				_signed;
	const int			_sign_requirement;
	const int			_exec_requirement;
};

std::ostream &operator<<( std::ostream &output, const Form& form );

#endif /* FORM_HPP */
