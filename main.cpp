#ifndef MAIN_H
#define MAIN_H
#include "mainwindow.h"
#include <QApplication>
#include "player.h"
#include <utility>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QRect>
#include <utility>
#include "staticgameobj.h"
#include <QList>
#include <QVector2D>
#include <vector>
#include <QLineF>
#include <memory>
#include "world.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    std::vector<QGraphicsRectItem *> staticgameobjs;

    auto player1 = new player();
    auto ground = new staticgameobj();
    auto scene = new QGraphicsScene();


    scene->addItem(player1);
    scene->addItem(ground);

    staticgameobjs.push_back(ground);
    staticgameobjs.push_back(new staticgameobj());
    staticgameobjs.push_back(new staticgameobj());

    scene->addItem(staticgameobjs.at(1));
    scene->addItem(staticgameobjs.at(2));
    scene->setSceneRect(QRectF{0,0,10000,2000});


    // make player focusable
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();

    auto view = new QGraphicsView();
    staticgameobjs.at(1)->setRect(100,1000,50,1000);
    staticgameobjs.at(2)->setRect(400,1111,50,1000);

    //view->centerOn(player1);
    view->setScene(scene);
    // show the view
    player1->p_view = view;
    view->show();


    auto _world = new world(player1,view);

    _world->add_static_obj(ground);
    _world->add_static_obj(staticgameobjs.at(1));
    _world->add_static_obj(staticgameobjs.at(2));

    //w.show();
    return a.exec();
}
#endif
