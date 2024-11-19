/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/30 13:13:24 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include "AForm.hpp"

# define GRADE_MAX 1
# define GRADE_MIN 150

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat	( void );
		Bureaucrat	( std::string name, int grade );
		Bureaucrat	( const Bureaucrat &other );
		Bureaucrat	&operator=( const Bureaucrat &other );
		~Bureaucrat	( void );

		std::string		getName( void ) const;
		int				getGrade( void ) const;

		void			incrementGrade( void );
		void			decrementGrade( void );
		Bureaucrat		&operator++( void );
		Bureaucrat		&operator--( void );
		Bureaucrat		operator++( int );
		Bureaucrat		operator--( int );

		void			signForm( AForm &form ) const;
		void			execForm( AForm &form ) const;

		class	GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		} ;
		class	GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		} ;

	private:
		const std::string	_name;
		int					_grade;
} ;

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &bcrat );

#endif

