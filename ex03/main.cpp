/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/20 19:58:38 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void	test_pardon(Bureaucrat &bcat)
{
	Intern	intern;

	std::cout << std::endl << "test_pardon" << std::endl;
	AForm *test_form = intern.makeForm("PresidentialPardonForm", "Trump");
	if (!test_form)
		return ;
	std::cout 	<< std::endl << "Testing bureaucrat " << bcat
	   			<< " with form " << *test_form << std::endl;
	try {
		bcat.signForm( *test_form );
		bcat.executeForm( *test_form );
	}
	catch (Bureaucrat::GradeException &e) {
		std::cout << e.what() << std::endl;
	}
	delete test_form;
}

void	test_robotomy(Bureaucrat &bcat)
{
	Intern	intern;

	std::cout << std::endl << "test_robotomy" << std::endl;
	AForm *test_form = intern.makeForm("RobotomyRequestForm", "Lunatic");
	if (!test_form)
		return ;
	std::cout	<< "Testing bureaucrat " << bcat
	   			<< " with form " << *test_form << std::endl;
	std::cout	<< std::endl;
	try {
		bcat.signForm( *test_form );
		bcat.executeForm( *test_form );
	}
	catch (Bureaucrat::GradeException &e) {
		std::cout << e.what() << std::endl;
	}
	delete test_form;
}

void	test_shrubs(Bureaucrat &bcat)
{
	Intern	intern;

	std::cout << std::endl << "test_shrubs" << std::endl;
	AForm *test_form = intern.makeForm("ShrubberyCreationForm", "Raspberry");
	if (!test_form)
		return ;
	std::cout	<< "Testing bureaucrat " << bcat
	   			<< " with form " << *test_form << std::endl;
	try {
		bcat.signForm( *test_form );
		bcat.executeForm( *test_form );
	}
	catch (Bureaucrat::GradeException &e) {
		std::cout << e.what() << std::endl;
	}
	delete test_form;
}

void	test_bureaucrat(std::string test_name, int test_grade)
{
	try	{
		Bureaucrat bcat(test_name, test_grade);
		test_shrubs( bcat );
		test_robotomy( bcat );
		test_pardon( bcat );
	}
	catch (Bureaucrat::GradeException &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	test_bureaucrat("Peter", 42);
	//test_bureaucrat("Bernie", 1);
	//test_bureaucrat("Helena", 150);
	//test_bureaucrat("Gareth", 0);
	return (0);
}
