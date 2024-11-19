/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/19 22:42:19 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern& other )
{
	(void) other;
}

Intern &Intern::operator=( const Intern& other ) {
	(void) other;
	return *this;
}

Intern::~Intern( void ) {}

AForm	*Intern::makeForm( std::string const name, std::string const target) const
{
	AForm *output;

	try
	{
		std::cout << "Intern tried to make form " << name << " with target "
					<< target << std::endl;
		output = writeForm( name, target );
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return output;
}

AForm	*Intern::writeForm( std::string const name, std::string const target) const
{
	std::string forms[3] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};

	int i = 0;
	while (i < 3 && name != forms[i])
		i++;
	switch (i)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		case 3:
			throw (BadFormException());
	}
	return NULL;
}

const char *Intern::BadFormException::what() const throw()
{
	return ("Form does not exist");
}
