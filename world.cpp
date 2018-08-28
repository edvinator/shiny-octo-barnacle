
#include "world.h"
#include <QDebug>
#include <QtMath>
#include <iostream>
#include <numeric>
#include <complex>
#include "comperator.h"
#include <QElapsedTimer>

void world::update()
{
    QElapsedTimer timer;
    timer.start();
    ourgamer->update();
    collision_handler.resolve_collision(staticgameobjs,*ourgamer);
    ourgamer->p_view->centerOn(ourgamer);


    ourgamer->player_outside_collision(staticgameobjs);
    qDebug() << "The update function took" << timer.nsecsElapsed() << "milliseconds";
}
