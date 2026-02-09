#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	// Orthodox Canonical Form
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( const ShrubberyCreationForm &that );
	~ShrubberyCreationForm( void );
	ShrubberyCreationForm &operator=( const ShrubberyCreationForm &that );

	// Constructor on string
	ShrubberyCreationForm( std::string target );
	void execute( const Bureaucrat &b ) const;
private:
	const std::string _target;
};

#endif // !SHRUBBERY_CREATION_FORM_HPP
