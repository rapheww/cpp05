/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:19:19 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/28 22:36:35 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string name, int gradeSign, int gradeExec);
        ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& source);
        ~ShrubberyCreationForm();

        const std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        
        void beSigned(const Bureaucrat& signer);
        void beexectued() const;
        const int gradeToSign = 145;
        const int gradeToExec = 137;
        
    private:
        std::string _target;
};