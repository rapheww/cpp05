/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:03:11 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/30 12:15:46 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern{
    public:
        Intern();
        Intern(const Intern& cpy);
        Intern& operator=(const Intern& source);
        ~Intern();
        
        AForm* makeShrubbery(std::string target);
        AForm* makeRobotomy(std::string target);
        AForm* makePresidential(std::string target);

        AForm* makeForm(std::string formType, std::string target);
        
        class InvalidFormName : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
};