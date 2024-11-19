/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/30 12:20:32 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm	( void );
		ShrubberyCreationForm	( std::string target );
		ShrubberyCreationForm	( const ShrubberyCreationForm &other );
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &other );
		~ShrubberyCreationForm	( void );

		void		execute(Bureaucrat const &executor) const;
		std::string getTarget( void ) const;
	private:
		std::string	const	_target;
} ;

#endif

