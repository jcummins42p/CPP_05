/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/21 14:54:01 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm("Presidential Pardon Form", 25, 5),
	_target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	AForm("Presidential Pardon Form", 25, 5),
	_target(target)
{}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) :
	AForm(	other.getName(),
			other.getSignRequirement(),
			other.getExecRequirement()),
	_target( other.getTarget() )
{}

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
		throw AForm::GradeTooLowException( getExecRequirement());
	std::cout << "Zaphod Beeblebrox pardons target " << _target << std::endl;
}
