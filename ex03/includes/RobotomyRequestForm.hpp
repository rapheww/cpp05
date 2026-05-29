/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:26:39 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/29 22:28:23 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& cpy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& source);
        ~RobotomyRequestForm();

        const std::string getTarget() const;
        
        void beExecute() const;
        static const int gradeToSign = 72;
        static const int gradeToExec = 45;
        
    private:
        std::string _target;
};