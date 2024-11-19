/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/30 16:22:21 by jcummins         ###   ########.fr       */
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
	if (bcrat.getGrade() > this->getExecRequirement())
		throw AForm::GradeTooLowException();
	std::cout << "Print ASCII tree in target " << _target << std::endl;
}
