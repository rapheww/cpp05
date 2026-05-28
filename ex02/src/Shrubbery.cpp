/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shrubbery.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:26:33 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/28 22:34:19 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"



std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm& toprint){
    o<<"ShrubberyCreationForm : name = "<<toprint.getName()<<" | is signed =  "<<toprint.getSigned()<<" | Grade required to sign = "<<toprint.getGradeSign()<<" | Grade required to exec = "<<toprint.getGradeExec();
    return o;
}