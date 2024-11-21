/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/21 13:09:08 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat( void ) :
	_name("none"),
	_grade(GRADE_MIN)
{}

Bureaucrat::Bureaucrat( std::string name, int grade ) :
	_name(name),
	_grade(grade)
{
	testGrade(_grade);
	std::cout << "Created new Bureaucrat " << *this << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) :
	_name(other._name),
	_grade(other._grade)
{
	testGrade(_grade);
	std::cout << "Created new Bureaucrat " << *this << std::endl;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other)
	{
		testGrade(other.getGrade());
		_grade = other.getGrade();
	}
	std::cout << "Copy assigned Bureaucrat " << other
				<< " grade to Bureaucrat " << *this << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {}

void Bureaucrat::testGrade( int grade ) {
	if (grade < GRADE_MAX) {
		throw GradeTooHighException(grade);
	}
	if (grade > GRADE_MIN) {
		throw GradeTooLowException(grade);
	}
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

Bureaucrat &Bureaucrat::operator++( void ) {
	testGrade(_grade + 1);
	_grade++;
	return (*this);
}

Bureaucrat &Bureaucrat::operator--( void ) {
	testGrade(_grade - 1);
	_grade--;
	return (*this);
}

Bureaucrat Bureaucrat::operator++( int ) {
	Bureaucrat out = *this;
	testGrade(_grade + 1);
	_grade++;
	return (out);
}

//	postcrement
Bureaucrat Bureaucrat::operator--( int ) {
	Bureaucrat out = *this;
	testGrade(_grade - 1);
	_grade--;
	return (out);
}

void	Bureaucrat::incrementGrade() {
	--(*this);
}

void	Bureaucrat::decrementGrade() {
	++(*this);
}

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &bcrat ) {
	os << bcrat.getName()	<< ", bureaucrat grade " << bcrat.getGrade();
	return (os);
}

const char * Bureaucrat::GradeException::what() const throw() {
	return _message.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException( int grade ) throw() {
	std::ostringstream oss;
	oss << "Grade " << grade << " too high";
	_message = oss.str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException( int grade ) throw() {
	std::ostringstream oss;
	oss << "Grade " << grade << " too low";
	_message = oss.str();
}
