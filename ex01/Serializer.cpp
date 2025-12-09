/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:18:00 by ssghioua          #+#    #+#             */
/*   Updated: 2025/12/02 07:18:01 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::~Serializer(void) {}

Serializer::Serializer(const Serializer& other) {
	(void)other;
}

Serializer&	Serializer::operator=(const Serializer& other) {
	(void)other;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
