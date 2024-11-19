/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/19 22:09:49 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm	( void );
		AForm	( std::string name, bool is_signed, int sign, int exec );
		AForm	( const AForm &other );
		AForm	&operator=( const AForm &other );
		virtual ~AForm	( void );

		std::string 	getName( void ) const ;
		int		getSignRequirement( void ) const;
		int		getExecRequirement( void ) const;
		bool	getSigned( void ) const;
		virtual std::string getTarget( void ) const = 0;

		void	beSigned( const Bureaucrat &bcrat );

		virtual void execute( const Bureaucrat &executor ) const = 0;

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

std::ostream &operator<<( std::ostream &os, const AForm &form );

#endif
