/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABaseMoveClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:13:43 by ovirchen          #+#    #+#             */
/*   Updated: 2018/10/07 15:13:45 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ABaseMoveClass.hpp"

ABaseMoveClass::ABaseMoveClass() {
}

ABaseMoveClass::~ABaseMoveClass() {
}

ABaseMoveClass::ABaseMoveClass(ABaseMoveClass const &src) {
	*this = src;
}

ABaseMoveClass& ABaseMoveClass::operator=(ABaseMoveClass const &src) {
	if (this != &src) {
		_x = src.getX();
		_y = src.getY();
		_figure = src.getFigure();
		_status = src.getStatus();
	}
	return *this;
}

// void ABaseMoveClass::init(int _win_x, int _win_y) {
// 	_x = (int)clock() % (_win_x - 4) + 2;
// 	_y = (rand() % (_win_y - 30) + 1) + (_win_y - 35);
// 	_status = true;
// }

// void ABaseMoveClass::initXY(int x, int y) {
// 	_x = x;
// 	_y = y;
// 	_status = true;
// }

bool ABaseMoveClass::getStatus() const {
	return _status;
}

void ABaseMoveClass::setStatus(bool f) {
	_status = f;
}


int ABaseMoveClass::getX() const{
	return _x;
}

int ABaseMoveClass::getY() const {
	return _y;
}

std::string ABaseMoveClass::getFigure() const {
	return _figure;
}