#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"

class Intern
{
public:
	// Orthodox Canonical Form
	Intern( void );
	Intern( const Intern &that );
	~Intern( void );
	Intern &operator=( const Intern &that );

	// Subject requirement
	Form *makeForm( const std::string form_type, std::string form_target ) const;
private:
	typedef Form *(Intern::*_function_ptr)(std::string) const;

	Form *_createShrubbery( std::string target ) const;
	Form *_createPardon( std::string target ) const;
	Form *_createRobotomy( std::string target ) const;

};

#endif // !INTERN_HPP
