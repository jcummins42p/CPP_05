/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/20 16:45:52 by jcummins         ###   ########.fr       */
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
{
	checkGrade(_sign_requirement);
	checkGrade(_exec_requirement);
}

Form::Form( const Form& other ) :
	_name(other._name),
	_sign_requirement(other._sign_requirement),
	_exec_requirement(other._exec_requirement),
	_is_signed(other._is_signed)
{
	checkGrade(_sign_requirement);
	checkGrade(_exec_requirement);
}

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

void	Form::checkGrade( int grade ) {
	if (grade < GRADE_MAX)
		throw GradeTooHighException( grade );
	if (grade > GRADE_MIN)
		throw GradeTooLowException( grade );
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
		throw Bureaucrat::GradeTooLowException(bcrat.getGrade());
	_is_signed = true;
}

const char * Form::GradeException::what() const throw()
{
	return _message.c_str();
}

Form::GradeTooLowException::GradeTooLowException( int grade ) throw()
{
	std::ostringstream oss;
	oss << "Error: Form Grade " << grade << " too low";
	_message = oss.str();
}

Form::GradeTooHighException::GradeTooHighException( int grade ) throw()
{
	std::ostringstream oss;
	oss << "Error: Form Grade " << grade << " too high";
	_message = oss.str();
}
