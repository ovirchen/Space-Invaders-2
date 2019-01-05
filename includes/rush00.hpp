// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   rush00.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 10:00:02 by akasamar          #+#    #+#             //
//   Updated: 2018/10/06 10:00:03 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RUSH00_HPP
#define RUSH00_HPP

#include "myGameClass.hpp"
#include "SpaceShipClass.hpp"
#include "EnemyShipClass.hpp"
#include "ABaseMoveClass.hpp"
#include "Asteroid.hpp"

void	checkPositionAll(SpaceShip *ship, Asteroid *aster, EnemyShip *enemy, BulletClass *bullArr, WINDOW * win);

#endif