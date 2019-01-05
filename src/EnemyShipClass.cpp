// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   EnemyClass.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 16:23:08 by akasamar          #+#    #+#             //
//   Updated: 2018/10/07 16:23:08 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "../includes/EnemyShipClass.hpp"

EnemyShip::EnemyShip()
{
    _posX = -1;
    _posY = -1;
    _posEnBulletX = -1;
    _posEnBulletY = -1;
    //bullet = new BulletClass[40];
    return ;
}

EnemyShip::~EnemyShip()
{
    delete [] bullet;
    return ;
}

void    EnemyShip::changePosBullX(int x)
{
    _posEnBulletX = x;
}
void    EnemyShip::changePosBullY(int y){
    _posEnBulletY = y;
}

int    EnemyShip::getPosBullX()
{
    return _posEnBulletX;
}
int    EnemyShip::getPosBullY(){
    return _posEnBulletY;
}