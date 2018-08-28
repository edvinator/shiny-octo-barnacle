#ifndef COLLISION_HANDELER_H
#define COLLISION_HANDELER_H
#include "player.h"

class Collision_handeler
{
    QPointF collision_normal(QRectF const &player_rectangle, QRectF const &GORect,QVector2D const &playerspeed,QRectF const & intersection_rect,player &playa) const;
public:
    Collision_handeler() = default;
    bool resolve_collision(std::vector<QGraphicsRectItem*> const &,player &);
};

#endif // COLLISION_HANDELER_H
