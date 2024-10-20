/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/20 19:08:11 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat( std::string name, int grade ) :
	name(name),
	grade(grade)
{}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) :
	name(other.name),
	grade(other.grade)
{}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other)
	{
		//	copy member variables
	}
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {}

std::string Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

Bureaucrat &Bureaucrat::operator++( void ) {
	if (grade != 0)
		grade--;
	return (*this);
}

Bureaucrat &Bureaucrat::operator--( void ) {
	if (grade != 0)
		grade++;
	return (*this);
}

Bureaucrat Bureaucrat::operator++( int ) {
	Bureaucrat out = *this;
	if (grade != 0)
		grade--;
	return (out);
}

Bureaucrat Bureaucrat::operator--( int ) {
	Bureaucrat out = *this;
	if (grade != 0)
		grade++;
	return (out);
}

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &bcrat ) {
	os << bcrat.getName()	<< ", bureaucrat grade " << bcrat.getGrade() << std::endl;
	return (os);
}
