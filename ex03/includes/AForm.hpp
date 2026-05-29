/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:47:24 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/29 22:29:32 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>

class Bureaucrat;

class AForm{
    public:
        AForm();
        AForm(std::string name, int gradeSign, int gradeExec);
        AForm(const AForm& cpy);
        AForm& operator=(const AForm& source);
        virtual ~AForm();

        const std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        
        virtual void beSigned(const Bureaucrat& signer);
        virtual void execute(Bureaucrat const & executor) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
        class UnsignedException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
    protected:
        virtual void beExecute() const = 0;
    private:
        const std::string _name;
        bool _isSigned;
        const int _requiredGradeSign;
        const int _requiredGradeExec;
          
};

std::ostream& operator<< (std::ostream& o, const AForm& toprint);