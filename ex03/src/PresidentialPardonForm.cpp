/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:57:51 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/29 22:28:47 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Presidential Pardon Form", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExec), _target("unknown target"){
    // std::cout<<"PPF default constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExec), _target(target){    
    // std::cout<<"PPF constructor called"<<std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : AForm(cpy){
    // std::cout<<"PPF copy constructor called"<<std::endl;
    *this = cpy;    
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source){
    // std::cout<<"PPF operator = called"<<std::endl;
    if (this != &source){
        _target = source._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    // std::cout<<"PPF destructor called"<<std::endl;
}

const std::string PresidentialPardonForm::getTarget() const{
    return _target;
}

void PresidentialPardonForm::beExecute() const{
    
    std::cout<<_target<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}

std::ostream& operator<<(std::ostream& o, const PresidentialPardonForm& toprint){
    o<<"PresidentialPardonForm : name = "<<toprint.getName()<<" | target = "<<toprint.getTarget()<<" | is signed =  "<<toprint.getSigned()<<" | Grade required to sign = "<<toprint.getGradeSign()<<" | Grade required to exec = "<<toprint.getGradeExec();
    return o;
}
