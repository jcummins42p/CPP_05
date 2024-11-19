/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/30 16:26:50 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat( void ) :
	_name("none"),
	_grade(GRADE_MIN)
{
	std::cout << "Constructed new default bureaucrat " << *this;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) :
	_name(name)
{
	if (grade < GRADE_MAX) {
		throw GradeTooHighException();
	}
	if (grade > GRADE_MIN) {
		throw GradeTooLowException();
	}
	else
		_grade = grade;
	std::cout << "Constructed new bureaucrat " << *this;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) :
	_name(other._name),
	_grade(other._grade)
{
	std::cout << "Constructed copied bureaucrat " << *this;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other)
	{
		if (other._grade < GRADE_MAX)
		{
			_grade = GRADE_MAX;
			throw Bureaucrat::GradeTooHighException();
		}
		if (other._grade > GRADE_MIN)
		{
			_grade = GRADE_MIN;
			throw Bureaucrat::GradeTooLowException();
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
	if (_grade != 0)
		_grade--;
	return (*this);
}

Bureaucrat &Bureaucrat::operator--( void ) {
	if (_grade != 0)
		_grade++;
	return (*this);
}

Bureaucrat Bureaucrat::operator++( int ) {
	Bureaucrat out = *this;
	if (_grade >= GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
	return (out);
}

Bureaucrat Bureaucrat::operator--( int ) {
	Bureaucrat out = *this;
	if (_grade <= GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
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

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "TooHighException";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "TooLowException";
}

void	Bureaucrat::signForm( AForm &form ) const {

	if (form.getSigned()) {
		std::cout 	<< _name << " couldn't sign " << form.getName()
					<< " because it is already signed" << std::endl;
	}
	else {
		form.beSigned( *this );
		std::cout << _name << " has signed form " << form.getName() << std::endl;
	}
}

void	Bureaucrat::execForm( AForm &form ) const {
	if (_grade <= form.getExecRequirement())
	{
		std::cout << _name << " has executed form " << form.getName() << std::endl;
		form.execute( *this );
	}
	else throw Bureaucrat::GradeTooLowException();
}
