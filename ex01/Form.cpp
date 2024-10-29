/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/29 16:41:33 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) :
	_name("Default"),
	_sign_requirement(GRADE_MIN),
	_exec_requirement(GRADE_MAX),
	_is_signed(false)
{}

Form::Form( std::string name, bool is_signed, int sign, int exec ) :
	_name(name),
	_sign_requirement(sign),
	_exec_requirement(exec),
	_is_signed(is_signed)
{}

Form::Form( const Form& other ) :
	_name(other._name),
	_sign_requirement(other._sign_requirement),
	_exec_requirement(other._exec_requirement),
	_is_signed(other._is_signed)
{}

Form &Form::operator=( const Form& other ) {
	if (this != &other)
	{
		_is_signed = other.getSigned();
	}
	return *this;
}

Form::~Form( void ) {}

std::ostream &operator<<( std::ostream &os, const Form &form ) {
	os 	<< form.getName() << std::endl
		<< "Grade to sign = " << form.getSignRequirement() << std::endl
		<< "Grade to exec = " << form.getExecRequirement() << std::endl;
	switch ((int)form.getSigned()) {
		case (1):
			os << "Is signed." << std::endl;
			break;
		case (0):
			os << "Is not signed." << std::endl;
	}
	return (os);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "TooHighException";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "TooLowException";
}

std::string Form::getName( void ) const {
	return _name;
}

int Form::getSignRequirement( void ) const {
	return _sign_requirement;
}

int Form::getExecRequirement( void ) const {
	return _exec_requirement;
}

bool Form::getSigned( void ) const {
	return _is_signed;
}

void	Form::beSigned( const Bureaucrat &bcrat ) {
	bool	qualified = (bcrat.getGrade() <= _sign_requirement);

	if (!qualified)
		throw Form::GradeTooLowException();
	_is_signed = true;
}
