/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:42:23 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/26 22:36:25 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& cpy);
        ~Bureaucrat();

        Bureaucrat& operator=(const Bureaucrat& source);

        const std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
    
        class GradeTooHighException : std::exception {
            public:
                virtual const char* what() const throw();  
        };
        
        class GradeTooLowException : std::exception {
            public:
                virtual const char* what() const throw();  
        };
        
    private:
        const std::string _name;
        int _grade;
        static const int highestGrade = 1;
        static const int lowestGrade = 150;
};

std::ostream& operator<< (std::ostream& o, const Bureaucrat& toprint);