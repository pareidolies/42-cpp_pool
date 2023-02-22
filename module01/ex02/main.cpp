/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smostefa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:29:50 by smostefa          #+#    #+#             */
/*   Updated: 2023/02/22 14:29:51 by smostefa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
	std::string * stringPTR = &string;
	std::string & stringREF = string;

	std::cout << "Memory address of the string:         " << &string << std::endl;
	std::cout << "Memory address held by stringPTR:     " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:     " << &stringREF << std::endl;

	std::cout << "Value of the string:                  " << string << std::endl;
	std::cout << "Value pointed to by stringPTR:        " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:        " << stringREF << std::endl;

    return (0);
}
