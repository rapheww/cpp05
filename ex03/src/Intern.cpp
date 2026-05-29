/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:02:55 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/29 23:13:39 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
    // std::cout<<"Inter Default Constructor called"<<std::endl;
}

Intern::Intern(const Intern& cpy){
    // std::cout<<"Inter Copy Constructor called"<<std::endl;
    *this = cpy;
}

Intern& Intern::operator=(const Intern& source){
    // std::cout<<"Inter operator '=' called"<<std::endl;
    (void)source;
    return *this;
}

Intern::~Intern(){
    // std::cout<<"Inter Destructor called"<<std::endl;
}