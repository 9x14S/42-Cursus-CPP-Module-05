#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
public:
	// Orthodox Canonical Form
	Intern( void );
	Intern( const Intern &that );
	~Intern( void );
	Intern &operator=( const Intern &that );

	// Subject requirement
	AForm *makeForm( const std::string form_type, std::string form_target ) const;
};

#endif // !INTERN_HPP
