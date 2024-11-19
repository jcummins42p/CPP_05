/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/30 16:59:57 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void	test_pardon(Bureaucrat &bcat)
{
	std::cout	<< std::endl;
	PresidentialPardonForm test_form("Trump");

	std::cout 	<< std::endl << "Testing bureaucrat " << bcat
	   			<< " with form " << test_form << std::endl;
	try { bcat.signForm( test_form ); }
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	try { bcat.execForm( test_form ); }
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}

void	test_robotomy(Bureaucrat &bcat)
{
	std::cout	<< std::endl;
	RobotomyRequestForm test_form("Lunatic");

	std::cout 	<< std::endl << "Testing bureaucrat " << bcat
	   			<< " with form " << test_form << std::endl;
	try { bcat.signForm( test_form ); }
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	try { bcat.execForm( test_form ); }
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}

void	test_shrubs(Bureaucrat &bcat)
{
	std::cout	<< std::endl;
	ShrubberyCreationForm test_form("Elderflower");
	std::cout	<< "Testing bureaucrat " << bcat
	   			<< " with form " << test_form << std::endl;

	try { bcat.signForm( test_form ); }
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	try { bcat.execForm( test_form ); }
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}

void	test_bureaucrat(std::string test_name, int test_grade)
{
	try	{
		Bureaucrat bcat(test_name, test_grade);
		test_shrubs( bcat );
		test_robotomy( bcat );
		test_pardon( bcat );
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl; }
	catch (Bureaucrat::GradeTooHighException &e) {
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
