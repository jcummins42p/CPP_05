/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/20 18:09:01 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat( void ) :
	_name("none"),
	_grade(GRADE_MIN)
{}

Bureaucrat::Bureaucrat( std::string name, int grade ) :
	_name(name)
{
	if (grade < GRADE_MAX) {
		throw GradeTooHighException(grade);
	}
	if (grade > GRADE_MIN) {
		throw GradeTooLowException(grade);
	}
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) :
	_name(other._name),
	_grade(other._grade)
{}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other)
	{
		if (other._grade < GRADE_MAX)
		{
			_grade = GRADE_MAX;
			throw Bureaucrat::GradeTooHighException(other.getGrade());
		}
		if (other._grade > GRADE_MIN)
		{
			_grade = GRADE_MIN;
			throw Bureaucrat::GradeTooLowException(other.getGrade());
		}
		else
			_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

Bureaucrat &Bureaucrat::operator++( void ) {
	if (_grade >= GRADE_MIN)
		throw Bureaucrat::GradeTooLowException(_grade + 1);
	else
		_grade--;
	return (*this);
}

Bureaucrat &Bureaucrat::operator--( void ) {
	if (_grade <= GRADE_MAX)
		throw Bureaucrat::GradeTooHighException(_grade - 1);
	else
		_grade++;
	return (*this);
}

Bureaucrat Bureaucrat::operator++( int ) {
	Bureaucrat out = *this;
	if (_grade >= GRADE_MIN)
		throw Bureaucrat::GradeTooLowException(_grade + 1);
	else
		_grade++;
	return (out);
}

Bureaucrat Bureaucrat::operator--( int ) {
	Bureaucrat out = *this;
	if (_grade <= GRADE_MAX)
		throw Bureaucrat::GradeTooHighException(_grade - 1);
	else
		_grade--;
	return (out);
}

void	Bureaucrat::incrementGrade() {
	(*this)--;
}

void	Bureaucrat::decrementGrade() {
	(*this)++;
}

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &bcrat ) {
	os << bcrat.getName()	<< ", bureaucrat grade " << bcrat.getGrade();
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
	catch (Bureaucrat::GradeException &e) {
		std::cout << e.what() << std::endl;
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
	catch (Bureaucrat::GradeException &e) {
		std::cout << e.what() << std::endl;
	}
}

// Bureaucrat exceptions

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
