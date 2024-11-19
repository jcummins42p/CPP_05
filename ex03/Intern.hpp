/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/19 22:35:46 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern	( void );
		Intern	( const Intern &other );
		Intern	&operator=( const Intern &other );
		~Intern	( void );

		AForm *makeForm ( std::string const name, std::string const target ) const;
		AForm *writeForm ( std::string const name, std::string const target ) const;

		class BadFormException : public std::exception
		{
			public:
				const char *what() const throw();
		} ;
} ;

#endif
