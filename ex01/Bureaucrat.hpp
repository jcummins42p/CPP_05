/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/21 14:48:09 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

# define GRADE_MAX 1
# define GRADE_MIN 150

class	Bureaucrat
{
	public:
		Bureaucrat	( void );
		Bureaucrat	( std::string name, int grade );
		Bureaucrat	( const Bureaucrat &other );
		Bureaucrat	&operator=( const Bureaucrat &other );
		~Bureaucrat	( void );

		std::string		getName() const;
		int				getGrade() const;

		void			incrementGrade();
		void			decrementGrade();
		Bureaucrat		&operator++( void );
		Bureaucrat		&operator--( void );
		Bureaucrat		operator++( int );
		Bureaucrat		operator--( int );

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

