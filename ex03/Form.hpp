#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include <string>

class Bureaucrat;

class Form
{
public:
	// Orthodox Canonical Form
	Form( void );
	Form( const Form& that );
	Form& operator=( const Form& that );
	virtual ~Form( void );

	// Main constructor
	Form( const std::string name, int sign_requirement, int exec_requirement);

	// Required methods
	void	beSigned( Bureaucrat &b );
	virtual void	execute( Bureaucrat const &b ) const = 0;

	// Getters
	const std::string	&getName( void )           const;
	bool				getSignedStatus( void )    const;
	int					getSignRequirement( void ) const;
	int					getExecRequirement( void ) const;

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

	class FormNotSignedException : public std::exception
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

#endif /* AFORM_HPP */
