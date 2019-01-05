/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:41:46 by ovirchen          #+#    #+#             */
/*   Updated: 2018/10/07 15:41:47 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_H
# define ASTEROID_H

#include "ABaseMoveClass.hpp"

class Asteroid : public ABaseMoveClass
{

public:
	Asteroid();
	Asteroid(Asteroid const &src);
	~Asteroid();

	Asteroid &operator=(Asteroid const &src);

	void init(int _win_x, int _win_y);
	void initXY(int x, int y);
	void move(WINDOW *win);
	void remove(WINDOW *win);
	void print(WINDOW *win);
};

#endif
