/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/20 19:31:56 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

class	Bureaucrat
{
	public:
		Bureaucrat	( std::string name, int grade );
		Bureaucrat	( const Bureaucrat &other );
		Bureaucrat	&operator=( const Bureaucrat &other );
		~Bureaucrat	( void );

		std::string		getName() const;
		int				getGrade() const;
		Bureaucrat		&operator++( void );
		Bureaucrat		&operator--( void );
		Bureaucrat		operator++( int );
		Bureaucrat		operator--( int );
	private:
		const std::string	name;
		int					grade;
} ;

std::ostream	&operator<<( std::ostream &os, const Bureaucrat &bcrat );

#endif

