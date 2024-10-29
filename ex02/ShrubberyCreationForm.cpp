/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/29 19:05:02 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) :
	_name( other.getName() ),
	_sign_requirement( other.getSignRequirement() ),
	_exec_requirement( other.getExecRequirement() ),
	_is_singed( other.getSigned() )
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	if (this != &other)
	{
		_is_signed = other.getSigned();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

bool	getSigned( void ) const {
	return _is_signed;
}
