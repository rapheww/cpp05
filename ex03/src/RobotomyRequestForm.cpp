/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:27:00 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/29 22:28:34 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Default Form", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExec), _target("unknown target"){
    // std::cout<<"RRF default constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Default Form", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExec), _target(target){    
    // std::cout<<"RRF constructor called"<<std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm(cpy){
    // std::cout<<"RRF copy constructor called"<<std::endl;
    *this = cpy;    
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& source){
    // std::cout<<"RRF operator = called"<<std::endl;
    if (this != &source){
        _target = source._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    // std::cout<<"RRF destructor called"<<std::endl;
}

const std::string RobotomyRequestForm::getTarget() const{
    return _target;
}

void RobotomyRequestForm::beExecute() const{
    std::cout<<"Krrrrrr....!!!!!!!!****&&&.. drilling noises... ###"<<std::endl;
    if (rand() % 2){
        std::cout<<_target<<" has been robotomized successfully"<<std::endl;
    }
    else{
        std::cout<<"Robotomy failed ... :/"<<std::endl;
    }
}

std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm& toprint){
    o<<"RobotomyRequestForm : name = "<<toprint.getName()<<" | target = "<<toprint.getTarget()<<" | is signed =  "<<toprint.getSigned()<<" | Grade required to sign = "<<toprint.getGradeSign()<<" | Grade required to exec = "<<toprint.getGradeExec();
    return o;
}
