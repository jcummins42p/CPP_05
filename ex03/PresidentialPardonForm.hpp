/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/11/21 12:38:35 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm	( std::string target );
		PresidentialPardonForm	( const PresidentialPardonForm &other );
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &other );
		~PresidentialPardonForm	( void );

		void		execute(Bureaucrat const &executor) const;
		std::string getTarget( void ) const;
	private:
		PresidentialPardonForm	( void );
		std::string	const	_target;
} ;

#endif

