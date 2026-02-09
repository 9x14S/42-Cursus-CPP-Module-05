#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

class AForm;

class Bureaucrat
{
public:
	Bureaucrat( void );
	Bureaucrat( const Bureaucrat &that);
	Bureaucrat &operator=( const Bureaucrat& that );
	~Bureaucrat( void );

	Bureaucrat( std::string name, int grade );

	// ex01
	void	signForm( AForm &form );
	// ex02
	void	executeForm( const AForm &form );

	const std::string	&getName( void ) const;
	int					getGrade( void ) const;
	void				incrementGrade( void );
	void				decrementGrade( void );

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
	int					_grade;
};

std::ostream &operator<<( std::ostream &output, const Bureaucrat& that );

#endif /* BUREAUCRAT_HPP */
