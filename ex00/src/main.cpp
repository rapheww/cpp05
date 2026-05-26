/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 19:50:07 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/26 22:59:08 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void createBureaucrat(const std::string& name, int grade){
    try{
        Bureaucrat valid(name, grade);
    }
    catch (Bureaucrat::GradeTooHighException& e){
        std::cout<<"Exception : "<<e.what()<<std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e){
        std::cout<<"Exception : "<<e.what()<<std::endl;
    }
}

int main(){
    std::cout<<"\n---Test Bureaucrat multiple creation\n";
    createBureaucrat("A", 1);
    createBureaucrat("B", 67);
    createBureaucrat("C", 0);
    createBureaucrat("D", 165);
    std::cout<<std::endl;

    std::cout<<"\n---Default Bureaucrat creation\n";
    Bureaucrat a;
    Bureaucrat b("Define", 45);
    
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<"Assigning b to a with =\n";
    b = a;
    std::cout<<b<<std::endl;
    
    std::cout<<"\n---Increment and Decrement";
    Bureaucrat c("John", 1);
    Bureaucrat d("Louis", 150);
    Bureaucrat e("Marc", 40);
    Bureaucrat f("Arthur", 60);
    
    std::cout<<std::endl<<c<<std::endl;
    std::cout<<d<<std::endl;
    std::cout<<e<<std::endl;
    std::cout<<f<<std::endl<<std::endl;
    
    try{
        c.incrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException& e){
        std::cout<<"Exception : "<<e.what()<<std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e){
        std::cout<<"Exception : "<<e.what()<<std::endl;
    }
    
    try{
        d.decrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException& e){
        std::cout<<"Exception : "<<e.what()<<std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e){
        std::cout<<"Exception : "<<e.what()<<std::endl;
    }
    std::cout<<std::endl;
    for (int i = 0; i < 5; i++){
        try{
            e.decrementGrade();
        }
        catch (Bureaucrat::GradeTooHighException& e){
            std::cout<<"Exception : "<<e.what()<<std::endl;
        }
        catch (Bureaucrat::GradeTooLowException& e){
            std::cout<<"Exception : "<<e.what()<<std::endl;
        }
        std::cout<<e<<std::endl;
    }
    std::cout<<std::endl;
    for (int i = 0; i < 5; i++){
        try{
            f.incrementGrade();
        }
        catch (Bureaucrat::GradeTooHighException& e){
            std::cout<<"Exception : "<<e.what()<<std::endl;
        }
        catch (Bureaucrat::GradeTooLowException& e){
            std::cout<<"Exception : "<<e.what()<<std::endl;
        }
        std::cout<<f<<std::endl;
    }
    return 0;
}