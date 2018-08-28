#ifndef STATICGAMEOBJ_H
#define STATICGAMEOBJ_H
#include <QRect>
#include <QGraphicsRectItem>
#include <QObject>
#include <QVector2D>
#include <utility>

class staticgameobj : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    staticgameobj();


signals:

public slots:
};

#endif // STATICGAMEOBJ_H
