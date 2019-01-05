/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkposition.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:15:04 by akasamar          #+#    #+#             */
/*   Updated: 2018/10/07 19:15:05 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush00.hpp"

void	checkPositionAll(SpaceShip *ship, Asteroid *aster, EnemyShip *enemy, BulletClass *bullArr, WINDOW * win)
{
	int i;
	int k = -1;
	int l;

	while (++k < 7)
	{
		i = -1;
		while (++i < 20)
		{
			l = -1;
			while (++l < 3)
			{
				if (ship->getPosY() == enemy[i].getPosY() && (ship->getPosX() + k) == (enemy[i].getPosX() + l))
				{
					enemy[i].changePosY(-1);
					enemy[i].changePosX(-1);
					ship->lostLife();
					if (ship->getLife() == 0)
                        return;
				}
			}
			if (aster[i].getStatus() && ship->getPosY() == aster[i].getY() && (ship->getPosX() + k) == aster[i].getX())
			{
                aster[i].remove(win);
                ship->lostLife();
                if (ship->getLife() == 0)
                    return;
            }
            if (enemy[i].getPosY() != -1 && enemy[i].getPosX() != -1)
            {
				if (ship->getPosY() == enemy[i].getPosBullY() && (ship->getPosX() + k) == enemy[i].getPosBullX())
				{
					enemy[i].changePosBullY(-1);
					enemy[i].changePosBullX(-1);
					ship->lostLife();
                    if (ship->getLife() == 0)
                        return;
				}
            }
		}

	}
	wattron(win, COLOR_PAIR(7));
	k = -1;
	while (++k < 20)
	{
		i = -1;
		while (++i < 40)
		{
			if (bullArr[i].getPosY() != -1 && bullArr[i].getPosX() != -1)
			{
				if (bullArr[i].getPosY() == aster[k].getY() && bullArr[i].getPosX() == aster[k].getX())
				{
					aster[k].remove(win);
					mvwprintw(win, bullArr[i].getPosY(), bullArr[i].getPosX(), "2");
					ship->changeScore(2);
					bullArr[i].changePosYbull(-1);
					bullArr[i].changePosXbull(-1);
				}
				if (bullArr[i].getPosY() == (aster[k].getY() - 1) && bullArr[i].getPosX() == aster[k].getX())
				{
					aster[k].remove(win);
					mvwprintw(win, bullArr[i].getPosY(), bullArr[i].getPosX(), "2");
					ship->changeScore(2);
					bullArr[i].changePosYbull(-1);
					bullArr[i].changePosXbull(-1);
				}
				l = -1;
				while (++l < 3)
				{
					if (bullArr[i].getPosY() == enemy[k].getPosY() && bullArr[i].getPosX() == (enemy[k].getPosX() + l))
					{
						mvwprintw(win, bullArr[i].getPosY(), bullArr[i].getPosX(), "1");
						ship->changeScore(1);
						enemy[k].changePosY(-1);
						enemy[k].changePosX(-1);
						bullArr[i].changePosYbull(-1);
						bullArr[i].changePosXbull(-1);
					}
					if (bullArr[i].getPosY() == (enemy[k].getPosY() - 1) && bullArr[i].getPosX() == (enemy[k].getPosX() + l))
					{
						mvwprintw(win, bullArr[i].getPosY(), bullArr[i].getPosX(), "1");
						ship->changeScore(1);
						enemy[k].changePosY(-1);
						enemy[k].changePosX(-1);
						bullArr[i].changePosYbull(-1);
						bullArr[i].changePosXbull(-1);
					}
				}
			}
		}
	}
	wattroff(win, COLOR_PAIR(7));
}


//enemy 20
//bullet 40
//aster 20

//корабль с астероидами
//корабль с врагами
//пули с врагами и астероидыd