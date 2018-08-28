#include "player.h"
#include "constants.h"
#include "comperator.h"
#include <QKeyEvent>
#include <cmath>
#include <QtMath>
#include <QDebug>
#include <QVector2D>
#include <QLineF>
player::player(): QObject{}, QGraphicsRectItem{}
{
    setRect(100, 300, 20, 20);
}

void player::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    if (event->key() == Qt::Key_Left){
        --move_dir;
    }
    else if (event->key() == Qt::Key_Right){
        ++move_dir;
    }
    else if (event->key() == Qt::Key_Space){
        contact_inf.space_down = true;
        if(contact_inf.ground_contact)
        {
            contact_inf.ground_contact = false;
            speed.setY(take_off_speed);
            return;
        }
        if(contact_inf.left_contact)
        {
            contact_inf.left_contact = false;

            speed.setY(take_off_speed);
            speed.setX(-take_off_side_speed);

        }
        if(contact_inf.right_contact)
        {
            contact_inf.right_contact = false;

            speed.setY(take_off_speed);
            speed.setX(take_off_side_speed);
        }
    }
}

void player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        return;
    if(event->key() == Qt::Key_Right){
        --move_dir;
    }
    else if(event->key() == Qt::Key_Left)
        ++move_dir;
    else if(event->key() == Qt::Key_Space)
        contact_inf.space_down = false;
}



void player::update()
{
    QVector2D acc{0.f,0.f};
    float target_speed = (move_dir.get()) * max_speed;
    float speed_diff = target_speed - speed.x();
    if(std::fabs(speed.y()) < max_y_speed)
    {
        if(contact_inf.space_down)
            speed.setY(speed.y() +_space_gravity);
        else
            speed.setY(speed.y() + _gravity);
    }

    if(speed_diff != 0.f)      //!_comperator(speed_diff,0.0f))
    {
        if(speed_diff < 0)
        {
            acc.setX( -move_accel);
        }
        else
        {
            acc.setX(move_accel);
        }
    }

    speed.setX(speed.x() + acc.x());
    setPos(pos()+= speed.toPointF());
    //qDebug()<<speed.toPointF().x()<<","<<speed.toPointF().y()<<'\n';

    lf._speed = speed;
    lf.rect = sceneBoundingRect();
}

void player::player_outside_collision(std::vector<QGraphicsRectItem*> &graphicsitems)
{
    if(current_colliding_elemt < 101)
    {
        auto coll_item =  graphicsitems[current_colliding_elemt]->sceneBoundingRect();
        auto player_rect = sceneBoundingRect();

        if(contact_inf.left_contact)
        {
            if(player_rect.bottom() < coll_item.top() || player_rect.top() > coll_item.bottom())
            {
                contact_inf.left_contact = false;
                current_colliding_elemt = 101;
            }
        }
        else if(contact_inf.right_contact)
        {
            if(player_rect.bottom() < coll_item.top() || player_rect.top() > coll_item.bottom())
            {
                contact_inf.right_contact = false;
                current_colliding_elemt = 101;

            }
        }
        else if(contact_inf.ground_contact)
        {
            if(player_rect.right() < coll_item.left() || player_rect.left() > coll_item.right())
            {
                contact_inf.ground_contact = false;
                current_colliding_elemt = 101;

            }
        }

    }
}


