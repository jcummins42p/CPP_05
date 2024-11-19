/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/30 16:21:34 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm("Presidential Pardon Form", false, 25, 5),
	_target("Default")
{
	std::cout << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	AForm("Presidential Pardon Form", false, 25, 5),
	_target(target)
{
	std::cout << this->getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) :
	AForm(other.getName(), other.getSigned(), other.getSignRequirement(), other.getExecRequirement()),
	_target( other.getTarget() )
{
	std::cout << this->getName() << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm& other ) {
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget( void ) const {
	return _target;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

void	PresidentialPardonForm::execute( const Bureaucrat &bcrat ) const {
	if (bcrat.getGrade() > this->getExecRequirement())
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Zaphod Beeblebrox pardons target " << _target << std::endl;
}
