/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/22 15:27:18 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMS_H
# define FORMS_H

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form	( void );
		Form	( std::string name, bool is_signed, int sign, int exec );
		Form	( const Form &other );
		Form	&operator=( const Form &other );
		~Form	( void );

		std::string 	getName( void ) const ;
		int 			getSignRequirement( void ) const ;
		int 			getExecRequirement( void ) const ;
		bool 			getSigned( void ) const ;

		void			beSigned( const Bureaucrat &bcrat );

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		} ;
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		} ;
	private:
		const std::string	_name;
		const int			_sign_requirement;
		const int			_exec_requirement;
		bool				_is_signed;
} ;

std::ostream &operator<<( std::ostream &os, const Form &form );

#endif
