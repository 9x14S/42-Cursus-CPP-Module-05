#ifndef ROBOTOMY_CREATION_FORM_HPP
# define ROBOTOMY_CREATION_FORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
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

#endif // !ROBOTOMY_CREATION_FORM_HPP
