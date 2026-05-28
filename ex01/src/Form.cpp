/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:47:19 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/28 22:06:05 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _requiredGradeSign(Bureaucrat::lowestGrade), _requiredGradeExec(Bureaucrat::lowestGrade){
    // std::cout<<"Default Form constructor called\n";
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _requiredGradeSign(gradeSign), _requiredGradeExec(gradeExec){
    // std::cout<<"Form constructor called\n";
    if (gradeExec > Bureaucrat::lowestGrade || gradeSign > Bureaucrat::lowestGrade)
        throw(Form::GradeTooLowException());
    if (gradeExec < Bureaucrat::highestGrade || gradeSign < Bureaucrat::highestGrade)
        throw(Form::GradeTooHighException());
}

Form::Form(const Form& cpy) : _name(cpy._name), _isSigned(false), _requiredGradeSign(cpy._requiredGradeSign), _requiredGradeExec(cpy._requiredGradeExec){
    // std::cout<<"Form copy constructor called\n";
}

Form::~Form(){
    // std::cout<<"Form destructor called\n";
}

Form& Form::operator=(const Form& source){
    // std::cout<<"Form operator = called\n";
    if (this != &source){
        _isSigned = source._isSigned;
    }
    return *this;
}

const std::string Form::getName() const{
    return _name;
}

bool Form::getSigned() const{
    return _isSigned;
}

int Form::getGradeSign() const{
    return _requiredGradeSign;   
}

int Form::getGradeExec() const{
    return _requiredGradeExec;
}

void Form::beSigned(const Bureaucrat& signer){
    if (signer.getGrade() <= _requiredGradeSign)
        _isSigned = true;
    else
        throw(Form::GradeTooLowException());
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Invalid Form Grade, your grade is too high";
}

const char *Form::GradeTooLowException::what() const throw(){
    return "Invalid Form Grade, your grade is too low";
}

std::ostream& operator<<(std::ostream& o, const Form& toprint){
    o<<"Form : name = "<<toprint.getName()<<" | is signed =  "<<toprint.getSigned()<<" | Grade required to sign = "<<toprint.getGradeSign()<<" | Grade required to exec = "<<toprint.getGradeExec();
    return o;
}