#ifndef PLAYER_H
#define PLAYER_H
#include <QRect>
#include <QGraphicsRectItem>
#include <QObject>
#include <QVector2D>
#include "comperator.h"
#include <utility>
#include <QGraphicsView>
#include <array>
#include <sstream>
#include <iterator>
//enum movedir{idle = 0, lef = -1, righ = 1};

struct last_frame
{
    QRectF rect;
    QVector2D _speed;

};
struct contact_inf
{
    bool ground_contact{false};
    bool left_contact{false};
    bool right_contact{false};
    bool space_down{false};
};

struct movedir
{
public:
    movedir& operator++()
    {
        if(dir==1)
            return *this;
        dir++;
        return *this;
    }
    movedir& operator--()
    {
        if(dir == -1)
            return *this;
        dir--;
        return *this;
    }
    int get() const
    {
        return dir;
    }
    void idle(){dir = 0;}
private:
    int8_t dir{0};
};

class player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    QVector2D speed {0.f,0.f};
    movedir move_dir{};
    comperator _comperator;

public:
    last_frame lf;
    contact_inf contact_inf;
    player();
    void keyPressEvent(QKeyEvent * event) override;
    void keyReleaseEvent(QKeyEvent * event) override;

    size_t current_colliding_elemt{101}; //bigger than 100 represents no colliding element

    void update ();
    void player_outside_collision(std::vector<QGraphicsRectItem*> &items);
    void y_speed_0() {speed.setY(0.f);}
    void x_speed_0() {speed.setX(0.f);}
    QGraphicsView *p_view;

    QVector2D get_speed(){
        return speed;
    }
signals:

public slots:

};

#endif // PLAYER_H
