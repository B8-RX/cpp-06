/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:11:01 by ssghioua          #+#    #+#             */
/*   Updated: 2025/12/02 07:11:02 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
	Data* originData = new Data("soso");

	std::cout << "originData ptr value = " <<  originData << "\n";
	std::cout << "originData name = " << originData->getName() << "\n";
	
	uintptr_t	dataSerialized = Serializer::serialize(originData);
	std::cout << "ptr value converted to uint = " << dataSerialized << "\n";

	Data*	recoveryData = Serializer::deserialize(dataSerialized);
	
	std::cout << "recoveryData ptr value = " << recoveryData << "\n";
	std::cout << "recoveryData name = " << recoveryData->getName() << "\n";
	
	delete originData;
	return (0);
}
