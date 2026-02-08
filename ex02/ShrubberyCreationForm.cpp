#include <fstream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

#define SHRUBBERY_SIGN_REQUIREMENT 145
#define SHRUBBERY_EXEC_REQUIREMENT 137

// Orthodox Canonical Form
ShrubberyCreationForm::ShrubberyCreationForm( void )
	:	AForm(
			"ShrubberyCreationForm",
			SHRUBBERY_SIGN_REQUIREMENT,
			SHRUBBERY_EXEC_REQUIREMENT),
		_target("ShrubberyCreationForm")
{}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &that )
	:	AForm(
			that.getName(),
			SHRUBBERY_SIGN_REQUIREMENT,
			SHRUBBERY_EXEC_REQUIREMENT),
		_target(that._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm & that)
{
	AForm::operator=(that);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{}

// Main stuff
ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	:	AForm(
			target,
			SHRUBBERY_SIGN_REQUIREMENT,
			SHRUBBERY_EXEC_REQUIREMENT),
		_target(target)
{}

void ShrubberyCreationForm::execute( const Bureaucrat &b ) const
{
	if (b.getGrade() > this->getExecRequirement())
		throw AForm::GradeTooLowException();
	else if (!this->getSignedStatus())
		throw AForm::FormNotSignedException();
	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: can't open file <" << filename << ">" << std::endl;
		return ;
	}
	outfile << "       _-_"        << std::endl;
	outfile << "    /~~   ~~\\"    << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~"  << std::endl;
	outfile << "_- -   | | _- _"   << std::endl;
	outfile << "  _ -  | |   -_"   << std::endl;
	outfile << "      // \\\\"     << std::endl;
	outfile.close();
}
