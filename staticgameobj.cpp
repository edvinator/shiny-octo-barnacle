#include "staticgameobj.h"

staticgameobj::staticgameobj() : QObject{}, QGraphicsRectItem {}
{
    setRect(25,1450,1000,500);
    //setRect(400, 300, 50, 70);
}
