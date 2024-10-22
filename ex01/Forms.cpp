/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Forms.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/22 15:08:37 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Forms.hpp"

Forms::Forms( void ) :
	_name("Default"),
	_sign_requirement(GRADE_MIN),
	_exec_requirement(GRADE_MAX),
	_is_signed(false)
{}

Forms::Forms( std::string name, bool is_signed, int sign, int exec ) :
	_name(name),
	_sign_requirement(sign),
	_exec_requirement(exec),
	_is_signed(is_signed)
{}

Forms::Forms( const Forms& other ) :
	_name(other._name),
	_sign_requirement(other._sign_requirement),
	_exec_requirement(other._exec_requirement),
	_is_signed(other._is_signed)
{}

Forms &Forms::operator=( const Forms& other ) {
	if (this != &other)
	{
		_is_signed = other.getSigned();
	}
	return *this;
}

Forms::~Forms( void ) {}

std::ostream &operator<<( std::ostream &os, const Forms &form ) {
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

const char * Forms::GradeTooHighException::what() const throw()
{
	return "TooHighException";
}

const char * Forms::GradeTooLowException::what() const throw()
{
	return "TooLowException";
}

std::string Forms::getName( void ) const {
	return _name;
}

int Forms::getSignRequirement( void ) const {
	return _sign_requirement;
}

int Forms::getExecRequirement( void ) const {
	return _exec_requirement;
}

bool Forms::getSigned( void ) const {
	return _is_signed;
}

void	Forms::beSigned( const Bureaucrat &bcrat ) {
	bool	qualified = (bcrat.getGrade() <= _sign_requirement);

	if (!qualified)
		throw Forms::GradeTooLowException();
	_is_signed = true;
}
