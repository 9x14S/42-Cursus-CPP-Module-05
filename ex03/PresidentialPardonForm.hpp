#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	// Orthodox Canonical Form
	PresidentialPardonForm( void );
	PresidentialPardonForm( const PresidentialPardonForm &that );
	~PresidentialPardonForm( void );
	PresidentialPardonForm &operator=( const PresidentialPardonForm &that );

	// Constructor on string
	PresidentialPardonForm( std::string target );
	void execute( const Bureaucrat &b ) const;
private:
	const std::string _target;
};

#endif // !PRESIDENTIAL_PARDON_FORM_HPP
