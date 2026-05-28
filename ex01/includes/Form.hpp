/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:47:24 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/28 20:42:34 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExec);
        Form(const Form& cpy);
        Form& operator=(const Form& source);
        ~Form();

        const std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        
        void beSigned(const Bureaucrat& signer);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
        
    private:
        const std::string _name;
        bool _isSigned;
        const int _requiredGradeSign;
        const int _requiredGradeExec;
          
};

std::ostream& operator<< (std::ostream& o, const Form& toprint);