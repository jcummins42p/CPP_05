/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/21 14:52:01 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) :
	_name("Default"),
	_sign_requirement(GRADE_MIN),
	_exec_requirement(GRADE_MIN),
	_is_signed(false)
{	std::cout << "Constructed new default form: " << _name << std::endl;}

AForm::AForm( std::string name, int sign, int exec ) :
	_name(name),
	_sign_requirement(sign),
	_exec_requirement(exec),
	_is_signed(false)
{
	checkGrade( sign );
	checkGrade( exec );
	std::cout << "Constructed new form: " << _name << std::endl;
}

AForm::AForm( const AForm& other ) :
	_name(other._name),
	_sign_requirement(other._sign_requirement),
	_exec_requirement(other._exec_requirement),
	_is_signed(other._is_signed)
{
	checkGrade( other.getSignRequirement() );
	checkGrade( other.getExecRequirement() );
	std::cout << "Copied form: " << _name
				<< " from existing form " << other << std::endl;
}

AForm &AForm::operator=( const AForm& other ) {
	if (this != &other)
	{
		_is_signed = other.getSigned();
	}
	return *this;
}

AForm::~AForm( void ) {
	std::cout << "Destroyed form " << getName() << std::endl;
}

void	AForm::checkGrade( int grade ) {
	if (grade < GRADE_MAX)
		throw (GradeTooHighException(grade));
	if (grade > GRADE_MIN)
		throw (GradeTooLowException(grade));
}

std::ostream &operator<<( std::ostream &os, const AForm &form ) {
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
		throw GradeTooLowException(getSignRequirement());
	_is_signed = true;
}

// AFORM Exceptions

const char *AForm::GradeException::what() const throw() {
	return _message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException( int grade ) throw() {
	std::ostringstream oss;
	oss << "Error: Form grade " << grade << " too low";
	_message = oss.str();
}

AForm::GradeTooHighException::GradeTooHighException( int grade ) throw() {
	std::ostringstream oss;
	oss << "Error: Form grade " << grade << " too high";
	_message = oss.str();
}
