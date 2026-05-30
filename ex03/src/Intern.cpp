/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 23:02:55 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/30 12:25:37 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){
    // std::cout<<"Inter Default Constructor called"<<std::endl;
}

Intern::Intern(const Intern& cpy){
    // std::cout<<"Inter Copy Constructor called"<<std::endl;
    *this = cpy;
}

Intern& Intern::operator=(const Intern& source){
    // std::cout<<"Inter operator '=' called"<<std::endl;
    (void)source;
    return *this;
}

Intern::~Intern(){
    // std::cout<<"Inter Destructor called"<<std::endl;
}

AForm* Intern::makeShrubbery(std::string target){
    return (new ShrubberyCreationForm(target));    
}
AForm* Intern::makeRobotomy(std::string target){
    return (new RobotomyRequestForm(target));   
}
AForm* Intern::makePresidential(std::string target){
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formType, std::string target){
    std::string allForm[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*fptr[3])(std::string target) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};
    
    for (int i = 0; i < 3; i++){
        if (allForm[i] == formType){
            AForm* form = (this->*fptr[i])(target);
            std::cout<<"Intern create "<<form->getName()<<std::endl;
            return form;
        }
    }
    throw(Intern::InvalidFormName());
}

const char *Intern::InvalidFormName::what() const throw(){
    return "Invalid form name, inter can't create it";
}