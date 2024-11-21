/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/21 13:19:57 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>
# include <sstream>	//	for ostringstream used in exception
# include "Form.hpp"

# define GRADE_MAX 1
# define GRADE_MIN 150

class	Form;

class	Bureaucrat
{
	public:
		Bureaucrat	( std::string name, int grade );
		Bureaucrat	( const Bureaucrat &other );
		Bureaucrat	&operator=( const Bureaucrat &other );
		~Bureaucrat	( void );

		std::string		getName( void ) const;
		int				getGrade( void ) const;

		void			checkGrade( int grade );

		void			incrementGrade( void );
		void			decrementGrade( void );
		Bureaucrat		&operator++( void );
		Bureaucrat		&operator--( void );
		Bureaucrat		operator++( int );
		Bureaucrat		operator--( int );

		void			signForm( Form &form );

		class	GradeException : public std::exception {
			public:
				GradeException( void ) throw() : _message("Grade Exception") {};
				virtual ~GradeException( void ) throw() {};

				const char *what() const throw();
			protected:
				std::string	_message;
		} ;
		class	GradeTooHighException : public GradeException {
			public:
				GradeTooHighException(int grade) throw();
		} ;
		class	GradeTooLowException : public GradeException {
			public:
				GradeTooLowException(int grade) throw();
		} ;

	private:
		Bureaucrat	( void );

		const std::string	_name;
		int					_grade;
} ;


std::ostream	&operator<<( std::ostream &os, const Bureaucrat &bcrat );

#endif
