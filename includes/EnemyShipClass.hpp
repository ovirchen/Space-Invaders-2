// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   EnemyClass.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 16:24:24 by akasamar          #+#    #+#             //
//   Updated: 2018/10/07 16:24:25 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMYSHIPCLASS_HPP
#define ENEMYSHIPCLASS_HPP

#include "SpaceShipClass.hpp"


class EnemyShip : public SpaceShip {
public:
    EnemyShip();

    ~EnemyShip();

    void changePosBullX(int x);

    void changePosBullY(int y);

    int getPosBullX();

    int getPosBullY();

private:
    int _posEnBulletX;
    int _posEnBulletY;
};

#endif



