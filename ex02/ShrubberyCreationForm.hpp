/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/29 18:32:26 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm	( void );
		ShrubberyCreationForm	( const ShrubberyCreationForm &other );
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &other );
		~ShrubberyCreationForm	( void );

		bool	getSigned( void ) const;
	private:
} ;

#endif

