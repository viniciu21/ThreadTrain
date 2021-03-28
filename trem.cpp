#include "trem.h"
#include <QtCore>
#include <QMutex>
#include <iostream>
#include <QSemaphore>

#define MAX_SPEED 120

QMutex *mutex1 = new QMutex();
QMutex *mutex2 = new QMutex();
QMutex *mutex3 = new QMutex();
QMutex *mutex4 = new QMutex();
QMutex *mutex5 = new QMutex();
QMutex *mutex6 = new QMutex();
QMutex *mutex7 = new QMutex();

QSemaphore *semaphoreRegion256 = new QSemaphore(2);
QSemaphore *semaphoreRegion457 = new QSemaphore(2);
QSemaphore *semaphoreRegion134 = new QSemaphore(2);

using namespace std;

//Construtor
Trem::Trem(int ID, int x, int y, int velocidade)
{
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = MAX_SPEED - velocidade;
}

//Função a ser executada após executar trem->START
void Trem::run()
{
    while (true)
    {
        switch (ID)
        {
        case 1: //Trem 1
            if (y == 70 && x < 310)
                if (x == 280){
                    semaphoreRegion134->acquire();
                    x += 10;
                }
                else if (x == 290)
                {
                    mutex1->lock();
                    x += 10;
                }
                else
                {
                    x += 10;
                }
            else if (x == 310 && y < 210)
                if (y == 190)
                {
                    mutex3->lock();
                    y += 10;
                }
                else
                {
                    y += 10;
                }
            else if (x > 40 && y == 210)
                if (x == 290)
                {
                    mutex1->unlock();
                    x -= 10;
                }
                else if (x == 160)
                {
                    mutex3->unlock();
                    semaphoreRegion134->release();
                    x -= 10;
                }
                else
                {
                    x -= 10;
                }
            else
                y -= 10;
            emit updateGUI(ID, x, y); //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 70 && x < 580)
                if (x == 330)
                {
                    mutex1->unlock();
                    x += 10;
                }
                else if (x == 550){
                    semaphoreRegion256->acquire();
                    x += 10;
                }
                else if (x == 560)
                {
                    mutex2->lock();
                    x += 10;
                }
                else
                {
                    x += 10;
                }
            else if (x == 580 && y < 210){
                if(y == 190){
                    mutex5->lock();
                    mutex4->unlock();
                    semaphoreRegion256->release();
//                    semaphoreRegion457->release();
                    y += 10;
                }
                else
                {
                    y += 10;
                }
            }
            else if (x > 310 && y == 210)
                if (x == 330)
                {
                    mutex1->lock();
                    x -= 10;
                }
                else if (x == 560)
                {
                    mutex2->unlock();
                    x -= 10;
                }
                else if (x == 430){
                    mutex5->unlock();
                    x-=10;
                }else if (x == 480){
                     semaphoreRegion134->acquire();
                     x -= 10;
                }
                else if (x == 470){
                    mutex4->lock();

                    x -= 10;
                }
                else
                {
                    x -= 10;
                }
            else {
                if(x == 310 && y == 190){
                    semaphoreRegion134->release();
                     y -= 10;
                }
                else if (y == 180){
//                    semaphoreRegion457->acquire();
                    y -= 10;
                }
                else {
                    y -= 10;
                }
            }
            emit updateGUI(ID, x, y); //Emite um sinal
            break;
        case 3: //Trem 3
            if (y == 70 && x < 850)
            {
                if (x == 600)
                {
                    mutex2->unlock();
                    x += 10;
                }
                else
                {
                    x += 10;
                }
            }
            else if (x == 850 && y < 210)
            {
                if(y == 190){
                    semaphoreRegion256->acquire();
                    y += 10;
                }else{
                    y += 10;
                }
            }
            else if (x > 580 && y == 210)
            {
                if (x == 600)
                {
                    mutex2->lock();
                    semaphoreRegion256->release();
                    x -= 10;
                }
                else if (x == 740)
                {
                    mutex6->lock();
                    x -= 10;
                }
                else
                {
                    x -= 10;
                }
            }
            else if (x == 580 && y > 70)
            {
                if (y == 190)
                {
                    mutex6->unlock();
                    y -= 10;
                }
                else
                {
                    y -= 10;
                }
            }
            emit updateGUI(ID, x, y); //Emite um sinal
            break;
        case 4: //Trem 4
            if (y == 210 && x < 450)
                if (x == 430)
                {
                    mutex7->lock();
                    semaphoreRegion134->release();
//                    semaphoreRegion457->release();
                    x += 10;
                }
                else if (x == 330)
                {
                    mutex3->unlock();
                    x += 10;
                }else if (x == 290){
                    mutex4->lock();
//                    semaphoreRegion457->acquire();
                    x += 10;
                }
                else
                {
                    x += 10;
                }
            else if (x == 450 && y < 330){
                   y += 10;
             }
            else if (x > 180 && y == 330)
                if (x == 430)
                {
                    mutex7->unlock();
                    x -= 10;
                }
                else if (x == 200){
                    semaphoreRegion134->acquire();
                    x -= 10;
                }
                else
                {
                    x -= 10;
                }
            else {
                if (x == 180 && y == 230)
                {
                    mutex3->lock();
                    mutex4->unlock();
                    y -= 10;
                 }
                else
                {
                    y -= 10;
                }
             }
            emit updateGUI(ID, x, y); //Emite um sinal
            break;
        case 5: //Trem 5
            if (y == 210 && x < 720)
            {
                if (x == 470)
                {
                    mutex7->unlock();
                    x += 10;
                }
                else if (x == 560)
                {
                    mutex6->lock();
                    semaphoreRegion256->acquire();
                    x += 10;
                }
                else if (x == 600){
                    mutex5->unlock();
                    semaphoreRegion256->release();
//                    semaphoreRegion457->release();
                    x+= 10;
                }
                else
                {
                    x += 10;
                }
            }
            else if (x == 720 && y < 330)
                if (y == 230)
                {
                    mutex6->unlock();
                    y += 10;
                }
                else
                {
                    y += 10;
                }
            else if (x > 450 && y == 330)
                if (x == 490){
//                    semaphoreRegion457->acquire();
                     x -= 10;
                }
                else if (x == 470)
                {
                    mutex7->lock();
                    x -= 10;
                }
                else
                {
                    x -= 10;
                }
            else if (x == 450 && y > 210){
                if(y == 230){
                    mutex5->lock();
                    y -= 10;
                }else {
                    y -= 10;
                }
            }
            emit updateGUI(ID, x, y); //Emite um sinal
            break;
        default:
            break;
        }
        msleep(this->velocidade);
    }
}
void Trem::mudarVelocidade(int velocidade) {
    if(velocidade == 0) {
        this->terminate();
    }
    else {
        if(this->isFinished()){
            this->start();
        }
        this->velocidade = MAX_SPEED - velocidade;
    }
}




