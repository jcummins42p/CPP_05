/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/20 18:36:18 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	AForm("Shubbery Creation Form", false, 145, 137),
	_target("Default")
{
	std::cout << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
	AForm("Shubbery Creation Form", false, 145, 137),
	_target(target)
{
	std::cout << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) :
	AForm(other.getName(), other.getSigned(), other.getSignRequirement(), other.getExecRequirement()),
	_target( other.getTarget() )
{
	std::cout << this->getName() << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget( void ) const {
	return _target;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

void	ShrubberyCreationForm::execute( const Bureaucrat &bcrat ) const {
	std::ofstream	fout;
	std::string		outfile = _target + "_shrubbery";

	if (bcrat.getGrade() > this->getExecRequirement())
		throw Bureaucrat::GradeTooLowException( bcrat.getGrade() );
	fout.open(outfile.c_str());
	if (!fout) {
		std::cout << "Error: file could not be opened" << std::endl;
		throw(std::exception());
	}

	fout 	<< "   *    *   *    " 	<< std::endl
			<< "  * | */* */     "	<< std::endl
			<< "    *\\ |* /*     "	<< std::endl
			<< "      \\| /       "	<< std::endl
			<< "       |/        "	<< std::endl
			<< "       |         "	<< std::endl
			<< "       |         "	<< std::endl
			<< std::endl;
	std::cout << "Printed ASCII tree in file " << outfile << std::endl;
}
