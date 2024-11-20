/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/20 15:48:07 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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
			throw Bureaucrat::GradeTooHighException(_grade);
		}
		if (other._grade > GRADE_MIN)
		{
			_grade = GRADE_MIN;
			throw Bureaucrat::GradeTooLowException(_grade);
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
	if (_grade <= GRADE_MIN)
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

const char * Bureaucrat::GradeException::what() const throw()
{
	return _message.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException( int grade ) throw()
{
	std::ostringstream oss;
	oss << "Grade " << grade << " too high";
	_message = oss.str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException( int grade ) throw()
{
	std::ostringstream oss;
	oss << "Grade " << grade << " too high";
	_message = oss.str();
}
