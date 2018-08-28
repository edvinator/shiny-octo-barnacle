#ifndef WORLD_H
#define WORLD_H
#include "player.h"
#include <vector>
#include <QObject>
#include "constants.h"
#include "comperator.h"
#include "collision_handeler.h"

#include <QDebug>
#include <QGraphicsItem>
#include <memory>
#include <QTimer>
#include <QGraphicsView>
class world : public QObject
{
    Q_OBJECT
    std::vector<QGraphicsRectItem *> staticgameobjs;
    player * ourgamer;
    Collision_handeler collision_handler;
    QGraphicsView * ourview;
    
public:
    world(player * ourplaya,QGraphicsView * ourview)
    {
        ourview = ourview;
        ourgamer = ourplaya;
        // spawn enemies
        QTimer * timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(update()));
        timer->start(25);
    }
    void add_static_obj(QGraphicsRectItem *item){
        staticgameobjs.push_back(item);
    }

signals:

public slots:
    void update();
};

#endif // WORLD_H
