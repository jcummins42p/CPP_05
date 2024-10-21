/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Forms.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcummins <jcummins@student.42prague.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:43:14 by jcummins          #+#    #+#             */
/*   Updated: 2024/10/21 15:38:30 by jcummins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Forms.hpp"

Forms::Forms( void ) {}

Forms::Forms( const Forms& other )
{
	//	copy constructor
}

Forms &Forms::operator=( const Forms& other ) {
	if (this != &other)
	{
		//	copy member variables
	}
	return *this;
}

Forms::~Forms( void ) {}

