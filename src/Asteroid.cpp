/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:41:57 by ovirchen          #+#    #+#             */
/*   Updated: 2018/10/07 15:41:58 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Asteroid.hpp"
#include <fstream>

Asteroid::Asteroid() {
	std::srand(time(0));
	_x = 0;
	_y = 0;
	_status = false;
	// std::string form[3] = {"$", "$$", "$$$"};
	// _figure = form[clock() % 3];
	_figure = "$";

}

Asteroid::Asteroid(Asteroid const &src) {
	*this = src;
}

Asteroid::~Asteroid() {
}

Asteroid& Asteroid::operator=(Asteroid const &src) {
	if (this != &src) {
		_x = src.getX();
		_y = src.getY();
		_figure = src.getFigure();
		_status = src.getStatus();
	}
	return *this;
}

void Asteroid::init(int _win_x, int _win_y) {
	if (_status == false)
	{
		_x = (rand() % (_win_x - 2)) + 1;
		_y = (rand() % (_win_y) - 44);
		_status = true;
	}
}

void Asteroid::initXY(int x, int y) {
	_x = x;
	_y = y;
	_status = true;
}

void Asteroid::move(WINDOW *win) {
	++_y;
	if (_y > 51)
		_status = false;
	if (_status == false && _y > 6)
		this->remove(win);
}

void Asteroid::remove(WINDOW *win) {
	wattron(win, A_BOLD | COLOR_PAIR(6));
	mvwprintw(win, _y, _x, " ");
	_status = false;
}

void Asteroid::print(WINDOW *win) {
	if (_status != false && _y > 6)
	{
		wattron(win, A_BOLD | COLOR_PAIR(6));
			mvwprintw(win, _y - 1, _x, "$");
	}
}
