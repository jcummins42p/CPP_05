/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/22 15:35:33 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) :
	_name("Default"),
	_sign_requirement(GRADE_MIN),
	_exec_requirement(GRADE_MAX),
	_is_signed(false)
{}

AForm::AForm( std::string name, bool is_signed, int sign, int exec ) :
	_name(name),
	_sign_requirement(sign),
	_exec_requirement(exec),
	_is_signed(is_signed)
{}

AForm::AForm( const AForm& other ) :
	_name(other._name),
	_sign_requirement(other._sign_requirement),
	_exec_requirement(other._exec_requirement),
	_is_signed(other._is_signed)
{}

AForm &AForm::operator=( const AForm& other ) {
	if (this != &other)
	{
		_is_signed = other.getSigned();
	}
	return *this;
}

AForm::~AForm( void ) {}

std::ostream &operator<<( std::ostream &os, const AForm &form ) {
	os 	<< form.getName() << std::endl
		<< "Grade to sign = " << form.getSignRequirement() << std::endl
		<< "Grade to exec = " << form.getExecRequirement() << std::endl;
	switch (form.getSigned()) {
		case (true):
			os << "Is signed." << std::endl;
			break;
		case (false):
			os << "Is not signed." << std::endl;
	}
	return (os);
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "TooHighException";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "TooLowException";
}

std::string AForm::getName( void ) const {
	return _name;
}

int AForm::getSignRequirement( void ) const {
	return _sign_requirement;
}

int AForm::getExecRequirement( void ) const {
	return _exec_requirement;
}

bool AForm::getSigned( void ) const {
	return _is_signed;
}

void	AForm::beSigned( const Bureaucrat &bcrat ) {
	bool	qualified = (bcrat.getGrade() <= _sign_requirement);

	if (!qualified)
		throw AForm::GradeTooLowException();
	_is_signed = true;
}
