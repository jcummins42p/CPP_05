/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/22 20:26:05 by jcummins         ###   ########.fr       */
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
		Form	( const std::string &name, const int &sign, const int &exec );
		Form	( const Form &other );
		Form	&operator=( const Form &other );
		~Form	( void );

		std::string 	getName( void ) const ;
		int 			getSignRequirement( void ) const ;
		int 			getExecRequirement( void ) const ;
		bool 			getSigned( void ) const ;

		void			checkGrade( int grade );

		void			beSigned( const Bureaucrat &bcrat );

		class GradeException : public std::exception {
			public:
				GradeException( void ) throw() : _message("Grade Exception") {};
				virtual ~GradeException( void ) throw() {};

				const char *what() const throw();
			protected:
				std::string _message;
		} ;
		class GradeTooHighException : public GradeException
		{
			public:
				GradeTooHighException( int grade ) throw();
		} ;
		class GradeTooLowException : public GradeException
		{
			public:
				GradeTooLowException( int grade ) throw();
		} ;
	private:
		Form	( void );

		const std::string	_name;
		const int			_sign_requirement;
		const int			_exec_requirement;
		bool				_is_signed;
} ;

std::ostream &operator<<( std::ostream &os, const Form &form );

#endif
