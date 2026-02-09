#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	// Orthodox Canonical Form
	RobotomyRequestForm( void );
	RobotomyRequestForm( const RobotomyRequestForm &that );
	~RobotomyRequestForm( void );
	RobotomyRequestForm &operator=( const RobotomyRequestForm &that );

	// Constructor on string
	RobotomyRequestForm( std::string target );
	void execute( const Bureaucrat &b ) const;
private:
	const std::string _target;
};

#endif // !ROBOTOMY_REQUEST_FORM_HPP
