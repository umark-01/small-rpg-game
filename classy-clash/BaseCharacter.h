
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"
#include "raymath.h"

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos()
    {
        return worldPos;
    }
    void undoMovement();
    Rectangle getCollisionRec();
    virtual void tick(float deltaTime);
    virtual Vector2 getScreenPos() = 0;
    bool getAlive() {
        return alive;
    }
    void setAlive(bool isAlive){
        alive = isAlive;
    }
protected:
    Vector2 worldPos{};
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 worldPosLastFrame{};
    // 1 facing right -1 facing left
    float rightleft{1.f};
    // animation var
    float runningTime{};
    float updateTime{1.f / 12.f};
    int frame{};
    int maxFrames{6};
    float speed = 4.f;
    float width{};
    float height{};
    float scale{4.0f};
    Vector2 velocity{};
private:
    bool alive{true};
};

#endif