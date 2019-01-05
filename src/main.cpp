// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: akasamar <akasamar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/06 09:52:33 by akasamar          #+#    #+#             //
//   Updated: 2018/10/06 09:52:34 by akasamar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "../includes/rush00.hpp"

WINDOW      *create_win(void)
{
    int     max_y;
    int     max_x;
    WINDOW  *win;

    max_y = 52;
    max_x = 82;
    win = newwin(max_y, max_x, 1, 1);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    return (win);
}

WINDOW    *startNcurse()
{
    WINDOW *win;

    initscr();
    win = create_win();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    nodelay(stdscr, true);
    start_color();
    return win;
}

void    forBackground(WINDOW *win)
{
    
    int x = 0;
    init_pair(1, COLOR_BLUE, COLOR_BLUE);
    init_pair(2, COLOR_YELLOW, COLOR_BLUE);
    init_pair(3, COLOR_WHITE, COLOR_BLUE);
    init_pair(4, COLOR_RED, COLOR_BLUE);
    init_pair(5, COLOR_BLACK, COLOR_BLUE);
    init_pair(6, COLOR_GREEN, COLOR_BLUE);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_BLACK);

    wattron(win, COLOR_PAIR(7));
    wattroff(win, A_BOLD);
    while (++x <= 80 )
        mvwprintw(win, 4, x, "-");
    wattron(win, COLOR_PAIR(1));
    for (int y = 5; y <= 50; y++)
        for (x = 1; x <= 80; x++)
            mvwprintw(win, y, x, " ");
    wattroff(win, COLOR_PAIR(1));

}

void    changePosStars(WINDOW *win, int i)
{
    wattron(win, COLOR_PAIR(2) | A_BOLD);
    int len = -1;
    static int arr[8][2] = {{34, 10}, {10, 15}, {25, 25}, {10, 35}, {6, 45}, {13, 55}, {45, 62}, {20, 78}};
    if (i == 2)
    {
        while (++len < 8)
            mvwprintw(win, arr[len][0], arr[len][1], "*");
    }
    if (i == 1)
        while (++len < 8) {
            if (arr[len][0] == 50) {
                arr[len][0] = 5;
            } else
                arr[len][0]++;

            mvwprintw(win, arr[len][0], arr[len][1], "*");
        }
    wattroff(win, COLOR_PAIR(2) | A_BOLD);
}

//void    drawStars()

void    fireBullet(SpaceShip *ship)
{
    int i = -1;
    BulletClass* bullArr = ship->getBullets();

    while (++i < 40)
        if (bullArr[i].getPosY() == -1 && bullArr[i].getPosY() == -1) {
            bullArr[i].changePosYbull(ship->getPosY());
            bullArr[i].changePosXbull(ship->getPosX() + 3);
            return ;
        }
}

void    mySpaceship(WINDOW *win, SpaceShip *ship)
{

    char c = getch();
    wattron(win, COLOR_PAIR(3) | A_BOLD);
    mvwprintw(win, ship->getPosY(), ship->getPosX(), "||<O>||");
    wattroff(win, COLOR_PAIR(3) | A_BOLD);
    if (c == 'a')
    {
        if (ship->getPosX() > 1)
            ship->changePosX(ship->getPosX() - 1);
    }
    else if (c == 'd')
    {
        if (ship->getPosX() < 74)
            ship->changePosX(ship->getPosX() + 1);
    }
    else if (c == 'w')
    {
        if (ship->getPosY() > 5)
            ship->changePosY(ship->getPosY() - 1);
    }
    else if (c == 's')
    {
        if (ship->getPosY() < 50)
            ship->changePosY(ship->getPosY() + 1);
    }
    else if (c == ' ')
        fireBullet(ship);
    else if (c == 27)
        ship->setLife();
    wattron(win, COLOR_PAIR(7));
    mvwprintw(win, 1, 1, "X ship:%d", ship->getPosX());
    mvwprintw(win, 2, 1, "Y ship:%d", ship->getPosY());
    mvwprintw(win, 2, 20, "score:%d    ", ship->getScore());
    mvwprintw(win, 2, 40, "life:%d  ", ship->getLife());
}

void    bulletCyclePosition(WINDOW *win, BulletClass* bullArr, int k)
{
    int i = -1;
    if (k == 1) {
        while (++i < 40) {
            if (bullArr[i].getPosY() < 6) {
                bullArr[i].changePosYbull(-1);
                bullArr[i].changePosXbull(-1);
            } else
                bullArr[i].changePosYbull(bullArr[i].getPosY() - 1);
        }
        i = -1;
        while (++i < 40) {
            wattron(win, COLOR_PAIR(4) | A_BOLD);
            mvwprintw(win, bullArr[i].getPosY(), bullArr[i].getPosX(), "o");
            wattroff(win, COLOR_PAIR(4) | A_BOLD);
        }
    }
    else if (k == 2)
    {
        i = -1;
        while (++i < 40) {
            wattron(win, COLOR_PAIR(4) | A_BOLD);
            if (bullArr[i].getPosY() != -1)
                mvwprintw(win, bullArr[i].getPosY(), bullArr[i].getPosX(), "o");
            wattroff(win, COLOR_PAIR(4) | A_BOLD);
        }
    }
}

void    createEnemy(EnemyShip *enemy, WINDOW *win, int k)
{
    int i = -1;
    if (k == 1) {
        while (++i < 20) {
            if (enemy[i].getPosY() == 50) {
                enemy[i].changePosY(-1);
                enemy[i].changePosX(-1);
            }
        }
        i = -1;
        while (++i < 20) {
            if (enemy[i].getPosY() == -1 && enemy[i].getPosX() == -1) {
                enemy[i].changePosY(5);
                enemy[i].changePosX((rand() % 77) + 1);
                break;
            }
        }
        i = -1;
        while (++i < 20) {
            wattron(win, COLOR_PAIR(4) | A_BOLD);
            mvwprintw(win, enemy[i].getPosY(), enemy[i].getPosX(), "v-v");
            wattroff(win, COLOR_PAIR(4) | A_BOLD);
            enemy[i].changePosY(enemy[i].getPosY() + 1);
        }
    }
    if (k == 2) {
        while (++i < 20) {
            wattron(win, COLOR_PAIR(4) | A_BOLD);
            if (enemy[i].getPosY() != -1)
                mvwprintw(win, enemy[i].getPosY(), enemy[i].getPosX(), "v-v");
            wattroff(win, COLOR_PAIR(4) | A_BOLD);
        }
    }
}

void    createEnemyBullet(EnemyShip *enemy)
{
    int i = -1;
    while(++i < 20)
        if (enemy[i].getPosY() != -1 && enemy[i].getPosX() != -1)
            if (enemy[i].getPosBullY() == -1 && enemy[i].getPosBullX() == -1) { //create one bullet
                enemy[i].changePosBullX(enemy[i].getPosX() + 1);
                enemy[i].changePosBullY(enemy[i].getPosY() + 1);
            }
}

void    showAndMoveEnemyBullet(EnemyShip* enemy, WINDOW *win, int z)
{
    wattron(win, A_BOLD | COLOR_PAIR(3) | A_STANDOUT);
    int i = -1;
    if (z == 2) {
        while (++i < 20) {
            if (enemy[i].getPosY() != 1 && enemy[i].getPosX() != 1) {
                if (enemy[i].getPosBullY() > 50) {
                    enemy[i].changePosBullY(-1);
                    enemy[i].changePosBullX(-1);
                }
                if (enemy[i].getPosBullY() != -1 && enemy[i].getPosBullX() != -1) {
                    mvwprintw(win, enemy[i].getPosBullY(), enemy[i].getPosBullX(), "+"); //show bullet
                }
            }
        }
    }
    if (z == 1)
    {
        while (++i < 20) { //move bullet on step
            if (enemy[i].getPosBullY() != -1 && enemy[i].getPosBullX() != -1)
                enemy[i].changePosBullY(enemy[i].getPosBullY() + 1);
        }
    }
    wattroff(win, A_BOLD | COLOR_PAIR(3) | A_STANDOUT);
}

void    cycleGame(WINDOW *win, SpaceShip *ship)
{
    unsigned int i = 0;
    int j;
    BulletClass* bullArr;
    EnemyShip *enemy = new EnemyShip[20];
    Asteroid *aster = new Asteroid[20];
    time_t end,start;
    while (ship->getLife() > 0)
    {
        time(&start);
        bullArr = ship->getBullets();
        forBackground(win);
        if (i % 15 == 0) {
            changePosStars(win, 1);
        }
        else
            changePosStars(win, 2);
        if (i % 8 == 0)
        {
            j = -1;
            while (++j < 20)
            {
                aster[j].init(80, 50);
                aster[j].move(win);
            }
        }
        j = -1;
            while (++j < 20)
                aster[j].print(win);
        if (i % 6 == 0)
            bulletCyclePosition(win, bullArr, 1);
        else
            bulletCyclePosition(win, bullArr, 2);

        if (i % 5 == 0)
            showAndMoveEnemyBullet(enemy, win, 1);
        else
            showAndMoveEnemyBullet(enemy, win, 2);
        if (i % 15 == 0)
            createEnemyBullet(enemy);
        if (i % 15 == 0)
            createEnemy(enemy, win, 1);
        else
            createEnemy(enemy, win, 2);
        mySpaceship(win, ship);
        checkPositionAll(ship, aster, enemy, bullArr, win);
        i++;
        wattron(win, COLOR_PAIR(7));
        wattroff(win, A_BOLD);
        mvwprintw(win, 2, 60, "time:%u     ", i / 10);
        time(&end);
        usleep(10000 - 1000 * difftime(end, start));
        wrefresh(win);
    }
    wattron(win, COLOR_PAIR(7));
    wattroff(win, A_BOLD);
    mvwprintw(win, 2, 40, "life:%d  ", ship->getLife());
    wattron(win, COLOR_PAIR(8) | A_STANDOUT);
    for (int y = 5; y <= 50; y++)
        for (int x = 1; x <= 80; x++)
            mvwprintw(win, y, x, " ");
    wattroff(win, COLOR_PAIR(8) | A_STANDOUT);
    wattron(win, A_BOLD);
    mvwprintw(win, 24, 35, "GAME OVER");
    wattroff(win, A_BOLD);
    wrefresh(win);
    sleep(3);
    endwin();
}


int main() //x 1-80 y 1-50
{
    WINDOW *win;
    win = startNcurse();
    SpaceShip *ship = new SpaceShip();
    MyGame *game = new MyGame(win);
    game->addShip(ship);
    cycleGame(win, game->getShip());

    return 0;
}
