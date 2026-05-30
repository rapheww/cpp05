/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:50:07 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/30 12:29:24 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void InternMakingform(Intern& slave, Bureaucrat& boss, std::string const& formToDo, std::string const& target){
    std::cout<<"\n---Intern Form Creation---"<<std::endl;
    AForm *form;
    try{
        form = slave.makeForm(formToDo, target);
        std::cout<<*form<<std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
    catch(const Intern::InvalidFormName& e){
        std::cout<<"Exception : "<<e.what()<<std::endl;
    }
}

int main(){
    Bureaucrat boss("Boss Carl", 1);
    Intern slave;
    std::string const form1 = "shrubbery creation";
    std::string const form2 = "robotomy request";
    std::string const form3 = "presidential pardon";
    std::string const form4 = "invalid form";
    
    std::cout<<boss<<std::endl;
    InternMakingform(slave, boss, form1, "target1");
    InternMakingform(slave, boss, form2, "target2");
    InternMakingform(slave, boss, form3, "target3");
    InternMakingform(slave, boss, form4, "target4");

    return 0;
}