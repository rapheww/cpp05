/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:42:23 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/29 22:08:29 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AForm;

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
        void signForm(AForm& Form) const;
        void executeForm(AForm const & form) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
        
        static const int highestGrade = 1;
        static const int lowestGrade = 150;

    private:
        const std::string _name;
        int _grade;
        
};

std::ostream& operator<< (std::ostream& o, const Bureaucrat& toprint);