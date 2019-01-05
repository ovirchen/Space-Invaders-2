/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABaseMoveClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:13:30 by ovirchen          #+#    #+#             */
/*   Updated: 2018/10/07 15:13:31 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABASEMOVECLASS_H
# define ABASEMOVECLASS_H

#include <iostream>
#include <ncurses.h>

class ABaseMoveClass {

public:
	ABaseMoveClass();
	ABaseMoveClass(ABaseMoveClass const &src);
	~ABaseMoveClass();

	ABaseMoveClass &operator=(ABaseMoveClass const &src);

	// void init(int _win_x, int _win_y);
	// void initXY(int x, int y);
	// virtual void move(WINDOW *win) = 0;
	// virtual void remove(WINDOW *win) = 0;

	bool getStatus() const;
	void setStatus(bool f);
	int getX() const;
	int getY() const;
	std::string getFigure() const;

protected:
	int _x;
	int _y;
	std::string _figure;
	bool _status;
};

#endif
