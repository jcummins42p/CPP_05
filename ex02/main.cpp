/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/22 15:18:29 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void	test_bureaucrat(std::string test_name, int test_grade)
{
	Forms planning("Planning permission", false, 42, 4);
	std::cout << "Testing new bureaucrat " << test_name << std::endl;
	try {
		 Bureaucrat bcat(test_name, test_grade);
		 try { bcat.signForm( planning ); }
		 catch (Forms::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		 }
		 catch (Forms::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		 }
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	test_bureaucrat("Peter", 42);
	test_bureaucrat("Bernie", 1);
	test_bureaucrat("Helena", 150);
	test_bureaucrat("Gareth", 0);
	return (0);
}
