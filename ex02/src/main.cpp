/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:50:07 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/30 12:17:22 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    std::srand(time(NULL));
    // AForm a;

    Bureaucrat lower("Will", 140);
    Bureaucrat middle("John", 50);
    Bureaucrat president("Mr. Lewis", 6);
    
    ShrubberyCreationForm scf;
    RobotomyRequestForm rrf;
    PresidentialPardonForm ppf;

    std::cout<<lower<<std::endl;
    std::cout<<middle<<std::endl;
    std::cout<<president<<std::endl;
    std::cout<<scf<<std::endl;
    std::cout<<rrf<<std::endl;
    std::cout<<ppf<<std::endl;
    
    std::cout<<"\n---Shrubbery Test---\n";
    lower.signForm(scf);
    lower.executeForm(scf);
    middle.executeForm(scf);

    std::cout<<"\n---Robotomy Test---\n";
    lower.signForm(rrf);
    middle.signForm(rrf);
    middle.executeForm(rrf);
    president.executeForm(rrf);
    
    std::cout<<"\n---President Test---\n";
    president.signForm(ppf);
    president.executeForm(ppf);
    president.incrementGrade();
    president.executeForm(ppf);
    return 0;
}