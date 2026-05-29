/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:47:19 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/29 22:29:43 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _isSigned(false), _requiredGradeSign(Bureaucrat::lowestGrade), _requiredGradeExec(Bureaucrat::lowestGrade){
    // std::cout<<"Default AForm constructor called\n";
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _requiredGradeSign(gradeSign), _requiredGradeExec(gradeExec){
    // std::cout<<"AForm constructor called\n";
    if (gradeExec > Bureaucrat::lowestGrade || gradeSign > Bureaucrat::lowestGrade)
        throw(AForm::GradeTooLowException());
    if (gradeExec < Bureaucrat::highestGrade || gradeSign < Bureaucrat::highestGrade)
        throw(AForm::GradeTooHighException());
}

AForm::AForm(const AForm& cpy) : _name(cpy._name), _isSigned(false), _requiredGradeSign(cpy._requiredGradeSign), _requiredGradeExec(cpy._requiredGradeExec){
    // std::cout<<"AForm copy constructor called\n";
}

AForm::~AForm(){
    // std::cout<<"AForm destructor called\n";
}

AForm& AForm::operator=(const AForm& source){
    // std::cout<<"AForm operator = called\n";
    if (this != &source){
        _isSigned = source._isSigned;
    }
    return *this;
}

const std::string AForm::getName() const{
    return _name;
}

bool AForm::getSigned() const{
    return _isSigned;
}

int AForm::getGradeSign() const{
    return _requiredGradeSign;   
}

int AForm::getGradeExec() const{
    return _requiredGradeExec;
}

const char *AForm::GradeTooHighException::what() const throw(){
    return "Invalid Grade, your grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw(){
    return "Invalid Grade, your grade is too low";
}

const char *AForm::UnsignedException::what() const throw(){
    return "The form isn't sign, sign it before executing";
}

void AForm::beSigned(const Bureaucrat& signer){
    if (signer.getGrade() <= _requiredGradeSign)
        _isSigned = true;
    else
        throw(AForm::GradeTooLowException());
}

void AForm::execute(const Bureaucrat& executor) const{
    if (this->getSigned() == false)
        return(throw(AForm::UnsignedException()));
    if (executor.getGrade() > this->_requiredGradeExec)
        return(throw(AForm::GradeTooLowException()));
    this->beExecute();
}


std::ostream& operator<<(std::ostream& o, const AForm& toprint){
    o<<"AForm : name = "<<toprint.getName()<<" | is signed =  "<<toprint.getSigned()<<" | Grade required to sign = "<<toprint.getGradeSign()<<" | Grade required to exec = "<<toprint.getGradeExec();
    return o;
}