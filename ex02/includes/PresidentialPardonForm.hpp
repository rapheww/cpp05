/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:58:07 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/29 22:28:28 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& cpy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& source);
        ~PresidentialPardonForm();

        const std::string getTarget() const;
        
        void beExecute() const;
        static const int gradeToSign = 25;
        static const int gradeToExec = 5;
        
    private:
        std::string _target;
};