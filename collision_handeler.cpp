#include "collision_handeler.h"
struct compare_points
{
    QPointF player_comp;
    QPointF static_ob_point;
};
QPointF Collision_handeler::collision_normal(QRectF const &player_rectangle, QRectF const &GORect,QVector2D const &playerspeed,QRectF const & intersection_rect,player &playa) const
{
    compare_points point{};
        if(playerspeed.x() > 0)
        {
            point.player_comp.setX(player_rectangle.right());
            point.static_ob_point.setX(GORect.left());
        }
        else
        {
            point.player_comp.setX(player_rectangle.left());
            point.static_ob_point.setX(GORect.right());
        }
        if(playerspeed.y() > 0)
        {
            point.player_comp.setY(player_rectangle.bottom());
            point.static_ob_point.setY(GORect.top());
        }
        else
        {
            point.player_comp.setY(player_rectangle.top());
            point.static_ob_point.setY(GORect.bottom());
        }
        qreal nr_steps_y = (point.static_ob_point.y() - point.player_comp.y()) / static_cast<qreal>(playerspeed.y());
        qreal nr_steps_x = (point.static_ob_point.x() - point.player_comp.x()) / static_cast<qreal>(playerspeed.x());
        if(std::fabs(nr_steps_x) < std::fabs(nr_steps_y) || std::isinf(std::fabs(nr_steps_y))) //move x dir
        {
            playa.x_speed_0();
            if(playerspeed.x() > 0.f)
            {
                playa.contact_inf.left_contact = true;
                return(QPointF{-intersection_rect.width()-1,0});
            }
            playa.contact_inf.right_contact = true;
            return QPointF{intersection_rect.width()+1,0};
        }
        playa.y_speed_0();
        if(playerspeed.y() > 0.f)
        {
            playa.contact_inf.ground_contact = true;
            return QPointF{0,-intersection_rect.height()-1};
        }
        return QPointF{0,intersection_rect.height()+1};
}

bool Collision_handeler::resolve_collision(const std::vector<QGraphicsRectItem *> &static_gos, player &player)
{
    auto pRect = player.sceneBoundingRect();
    bool resolvedcoll{false};
    for(size_t i{0}; i < static_gos.size(); i++)
    {
        auto GORect{static_gos.at(i)->sceneBoundingRect()};
        if(pRect.intersects(GORect))
        {
            //qDebug("moving in collision handler");
            auto intersection_rect{pRect.intersected(GORect)};
            QPointF normal{collision_normal(player.lf.rect,GORect,player.lf._speed,intersection_rect,player)};
            player.moveBy(normal.x(),normal.y());
            player.current_colliding_elemt = i;

            resolvedcoll = true;

        }

    }
    return resolvedcoll;
}


