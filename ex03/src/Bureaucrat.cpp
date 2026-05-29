/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:54:31 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/29 22:47:37 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150){
    // std::cout<<"Default Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(Bureaucrat::lowestGrade){
    // std::cout<<"Bureaucrat constructor called\n";
    if (grade > Bureaucrat::lowestGrade)
        throw(Bureaucrat::GradeTooLowException());
    else if (grade < Bureaucrat::highestGrade)
        throw(Bureaucrat::GradeTooHighException());
    else
        _grade = grade;
        
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy){
    *this = cpy;
    // std::cout<<"Bureaucrat copy constructor called\n";
}

Bureaucrat::~Bureaucrat(){
    // std::cout<<"Bureaucrat destructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& source){
    // std::cout<<"Bureaucrat operator = called\n";
    if (this != &source)
        this->_grade = source._grade;
    return *this;
}

const std::string Bureaucrat::getName() const{
    return _name;
}

int Bureaucrat::getGrade() const{
    return _grade;
}

void Bureaucrat::incrementGrade(){
    if (_grade - 1 < 1){
        return (throw(Bureaucrat::GradeTooHighException()));
    }
    _grade--;
}

void Bureaucrat::decrementGrade(){
    if (_grade + 1 > 150){
        return (throw(Bureaucrat::GradeTooLowException()));
    }
    _grade++;
}

void Bureaucrat::signForm(AForm& form) const{
    try{
        form.beSigned(*this);
        std::cout<<_name<<" signed "<<form.getName()<<std::endl;
    }
    catch(const std::exception &e){
        std::cout<<_name<<" couldn't sign "<<form.getName()<<" because "<<e.what()<<std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const{
    try{
        form.execute(*this);
        std::cout<<_name<<" executed "<<form.getName()<<std::endl;
    }
    catch(const AForm::GradeTooLowException& e){
        std::cout<<_name<<" can't execute "<<form.getName()<<" because : "<<e.what()<<std::endl;
    }
    catch(const AForm::UnsignedException& e){
        
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Invalid Grade, 1 is the highest grade";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Invalid Grade, 150 is the lowest grade";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& toprint){
    o<<"Bureaucrat is "<<toprint.getName()<<" and grade is "<<toprint.getGrade();
    return o;
}