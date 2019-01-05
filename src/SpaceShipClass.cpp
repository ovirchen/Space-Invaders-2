// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SpaceShip.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 12:10:51 by akasamar          #+#    #+#             //
//   Updated: 2018/10/06 12:10:54 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../includes/rush00.hpp"

SpaceShip::SpaceShip() : _posX(38), _posY(50)
{
    bullet = new BulletClass[40];
    _score = 0;
    _life = 5;
    return ;
}

void    SpaceShip::changePosX(int x)
{
    _posX = x;
}
void    SpaceShip::changePosY(int y){
    _posY = y;
}

void    SpaceShip::changeScore(int s){
    _score += s;
}

int    SpaceShip::getPosX()
{
    return _posX;
}
int    SpaceShip::getPosY(){
    return _posY;
}

int    SpaceShip::getLife(){
    return _life;
}

BulletClass*   SpaceShip::getBullets()
{
    return bullet;
}

int SpaceShip::getScore()
{
	return _score;
}

void    SpaceShip::lostLife()
{
	--_life;
}

void    SpaceShip::setLife()
{
    _life = 0;
}

SpaceShip::~SpaceShip()
{
    delete [] bullet;
    return ;
}

