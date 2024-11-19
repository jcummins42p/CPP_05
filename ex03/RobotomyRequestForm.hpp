/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:44:19 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/30 13:30:14 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm	( void );
		RobotomyRequestForm	( std::string target );
		RobotomyRequestForm	( const RobotomyRequestForm &other );
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &other );
		~RobotomyRequestForm	( void );

		void		execute(Bureaucrat const &executor) const;
		std::string getTarget( void ) const;
	private:
		std::string	const	_target;
} ;

#endif

