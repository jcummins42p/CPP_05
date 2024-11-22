/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/22 20:29:57 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include <sstream>
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm	( const std::string &name, const int &sign, const int &exec );
		AForm	( const AForm &other );
		AForm	&operator=( const AForm &other );
		virtual ~AForm	( void );

		std::string 	getName( void ) const ;
		int				getSignRequirement( void ) const;
		int				getExecRequirement( void ) const;
		bool			getSigned( void ) const;
		std::string 	getTarget( void ) const;

		void	beSigned( const Bureaucrat &bcrat );
		void	checkGrade( int grade );

		virtual void execute( const Bureaucrat &executor ) const = 0;

		class GradeException : public std::exception {
			public:
				GradeException( void ) throw() : _message("Form Grade Exception") {};
				virtual ~GradeException( void ) throw() {};

				const char *what() const throw();
			protected:
				std::string	_message;
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
		AForm	( void );

		const std::string	_name;
		const int			_sign_requirement;
		const int			_exec_requirement;
		bool				_is_signed;
} ;

std::ostream &operator<<( std::ostream &os, const AForm &form );

#endif
