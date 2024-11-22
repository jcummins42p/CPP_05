/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/22 20:34:01 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat( void ) :
	_name("none"),
	_grade(GRADE_MIN)
{}

Bureaucrat::Bureaucrat( const std::string &name, int grade ) :
	_name(name),
	_grade(grade)
{
	checkGrade(grade);
	std::cout << "Constructed new " << *this;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) :
	_name(other._name),
	_grade(other._grade)
{
	checkGrade(other.getGrade());
	std::cout << "Constructed copied " << *this << " from " << other;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other)
	{
		checkGrade(other.getGrade());
		_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {}

void	Bureaucrat::checkGrade( int grade ) {
	if (grade < GRADE_MAX)
		throw Bureaucrat::GradeTooHighException(grade);
	if (grade > GRADE_MIN)
		throw Bureaucrat::GradeTooLowException(grade);
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

Bureaucrat &Bureaucrat::operator++( void ) {
	checkGrade(_grade + 1);
	_grade++;
	return (*this);
}

Bureaucrat &Bureaucrat::operator--( void ) {
	checkGrade(_grade - 1);
	_grade--;
	return (*this);
}

Bureaucrat Bureaucrat::operator++( int ) {
	Bureaucrat out = *this;
	try {
		checkGrade(_grade + 1);
		_grade++;
	}
	catch (Bureaucrat::GradeException &e) {
		std::cout << e.what() << ": could not apply ++ operator" << std::endl;
	}
	return (out);
}

Bureaucrat Bureaucrat::operator--( int ) {
	Bureaucrat out = *this;
	try {
		checkGrade(_grade - 1);
		_grade--;
	}
	catch (Bureaucrat::GradeException &e) {
		std::cout << e.what() << ": could not apply -- operator" << std::endl;
	}
	return (out);
}

void	Bureaucrat::incrementGrade() {
	--(*this);
}

void	Bureaucrat::decrementGrade() {
	++(*this);
}

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &bcrat ) {
	os << bcrat.getName()	<< ", bureaucrat grade "
		<< bcrat.getGrade() << std::endl;
	return (os);
}

void	Bureaucrat::signForm( AForm &form ) {
	std::cout 	<< getName() << " is trying to sign form: "
				<< form.getName() << std::endl;
	if (form.getSigned()) {
		std::cout 	<< _name << " couldn't sign " << form.getName()
					<< " because it is already signed" << std::endl;
	}
	else try {
		form.beSigned(*this);
		std::cout 	<< _name << " has signed form: "
					<< form.getName() << std::endl;
	}
	catch (AForm::GradeException &e) {
		std::cout << e.what() << ": Bureaucrat " << _name << " could not sign " << form.getName() << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm &form ) {
	std::cout 	<< getName() << " is trying to execute form: "
				<< form.getName() << std::endl;
	if (!form.getSigned()) {
		std::cout 	<< _name << " couldn't execute " << form.getName()
					<< " because it is not signed" << std::endl;
	}
	else try { form.execute(*this); }
	catch (AForm::GradeException &e) {
		std::cout << e.what() << ": Bureaucrat " << _name << " could not sign " << form.getName() << std::endl;
	}
}

const char * Bureaucrat::GradeException::what() const throw()
{
	return _message.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException( int grade ) throw()
{
	std::ostringstream oss;
	oss << "Error: Bureaucrat grade " << grade << " too high";
	_message = oss.str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException( int grade ) throw()
{
	std::ostringstream oss;
	oss << "Error: Bureaucrat Grade " << grade << " too low";
	_message = oss.str();
}
