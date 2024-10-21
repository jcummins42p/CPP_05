/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/21 15:24:41 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void	test_bureaucrat(std::string test_name, int test_grade)
{
	std::cout << "Testing new bureaucrat " << test_name << std::endl;
	try {
		 Bureaucrat bcat(test_name, test_grade);
		 bcat.incrementGrade();
		 std::cout << bcat << std::endl;
		 bcat.decrementGrade();
		 std::cout << bcat << std::endl;
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
