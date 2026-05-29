/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:19:19 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/29 22:28:20 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& source);
        ~ShrubberyCreationForm();

        const std::string getTarget() const;
        
        void beExecute() const;
        static const int gradeToSign = 145;
        static const int gradeToExec = 137;
        
    private:
        std::string _target;
};