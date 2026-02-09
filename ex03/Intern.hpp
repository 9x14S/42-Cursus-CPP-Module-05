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
private:
	typedef AForm *(Intern::*_function_ptr)(std::string) const;

	AForm *_createShrubbery( std::string target ) const;
	AForm *_createPardon( std::string target ) const;
	AForm *_createRobotomy( std::string target ) const;

};

#endif // !INTERN_HPP
