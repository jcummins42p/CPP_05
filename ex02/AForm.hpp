/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/29 19:06:13 by jcummins         ###   ########.fr       */
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
		~AForm	( void );

		virtual std::string 	getName( void ) const ;
		virtual int		getSignRequirement( void ) const;
		virtual int		getExecRequirement( void ) const;
		virtual bool	getSigned( void ) const = 0;

		virtual void	beSigned( const Bureaucrat &bcrat );

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
	protected:
		const std::string	_name;
		const int			_sign_requirement;
		const int			_exec_requirement;
		bool				_is_signed;
} ;

std::ostream &operator<<( std::ostream &os, const AForm &form );

#endif
