/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/20 17:35:18 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void	test_bureaucrat(std::string test_name, int test_grade)
{
	try {
		Form planning("Planning permission", true, 42, 4);
		Bureaucrat bcat(test_name, test_grade);
		std::cout << "Testing new bureaucrat " << bcat.getName() << std::endl;
		bcat.signForm( planning );
	}
	catch (Form::GradeException &e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeException &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	test_bureaucrat("Peter", 43);
	test_bureaucrat("Bernie", 1);
	test_bureaucrat("Helena", 150);
	test_bureaucrat("Gareth", 0);
	return (0);
}
