#ifndef ENEMY_H
#define ENEMY_H
#include <QRect>
#include <QDebug>
#include <QString>
#include "Box2D/Box2D.h"
#include "engine.h"

class Enemy
{
public:
    Enemy();
    QRectF pos; //Koordinaten
    QRectF oldpos;
    QString name;
    int stunned=0;
    int maxStun=0;
    bool isUsed = false;
    bool blocked = false;
    int newdir = 1;
    int soonBanned = 0;
    bool physicsInitialized = false;
    uint16_t ownCategoryBits;
    uint16_t collidingCategoryBits;
    int repost = 0;
    int maxRepost = 0;
    int poison = 0;
    int poisonDmg = 1;
    int maxPoison = 0;
    int cpos; //Knoten von Weg
    int dir;
    int reload = 0;
    int maxReload = 0;
    int imgID = 0;
    double health; //Leben
    double preHealth;
    double maxHealth;
    int type = 0;
    int path = -1;
    int animation = 0;
    int price = 0;
    double healthWidth;
    double healthWidthTarget;
    int flash = 0;
    double speed;
    double newspeed;
    double ospeed; //originalgeschwindigkeit
    double opacity = 0;
    b2Body *body;
    void init(QRectF pos, double speed, int type, int cpos=0, int health=100, int path=0, int price=25);
    void initPhysics(b2World *world);
    void moveBy(double xv, double yv);
    void moveTo(double x, double y);
    void setHealth(int health);
    void setSpeed(double speed);
    void setStun(int stunAmount);
    void setRepost(int repostAmount);
    void reduceHealth(double amount);
    void free();
    void updatePos();
    void calcWidth();
    void updateWidth(double amount = 0.3);
    static int getDensity(int type);
    QRect rect();
    QRectF rectF(int a=0);
    QRectF centerRect();
    QString toString();
};

#endif // ENEMY_H
