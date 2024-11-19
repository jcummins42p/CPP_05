/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/19 22:42:46 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void	test_bureaucrat(std::string test_name, int test_grade)
{
	Intern intern;

	AForm *anyform = intern.makeForm( "RobotomyRequestForm", "kevin" );
	if (!anyform)
		return ;
	try	{
		Bureaucrat bcat(test_name, test_grade);
		bcat.signForm( *anyform );
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl; }
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl; }
	catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	delete anyform;
}

int	main(void)
{
	test_bureaucrat("Peter", 42);
	//test_bureaucrat("Bernie", 1);
	//test_bureaucrat("Helena", 150);
	//test_bureaucrat("Gareth", 0);
	return (0);
}
