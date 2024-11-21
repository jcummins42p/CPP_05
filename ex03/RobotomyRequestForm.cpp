/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/21 14:54:44 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>	// required for rand()

RobotomyRequestForm::RobotomyRequestForm( void ) :
	AForm("Robotomy Request Form", 72, 45),
	_target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) :
	AForm("Robotomy Request Form", 72, 45),
	_target(target)
{}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) :
	AForm(	other.getName(),
			other.getSignRequirement(),
			other.getExecRequirement()),
	_target( other.getTarget() )
{}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget( void ) const {
	return _target;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

void	RobotomyRequestForm::execute( const Bureaucrat &bcrat ) const {
	if (bcrat.getGrade() > this->getExecRequirement())
		throw GradeTooLowException(getExecRequirement());
	std::cout << "*** LOUD DRILLING SOUNDS *** : ";
	srand(time(0));
	if (rand() % 2 == 0)
		std::cout << "Robotomoized target " << _target << std::endl;
	else
		std::cout << "failed to robotomize target " << _target << std::endl;
}
