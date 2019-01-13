#include "Decors.hpp"

std::string const  Decors::spritePool[4][6] = {
    {
        "     ***          ",
        "    *******       ",
        "   ************   ",
        "  **************  ",
        "******************",
        ""
    },
    {
        "                  ",
        "    *             ",
        "   ****           ",
        "  *************   ",
        "******************",
        ""
    },
    {
        "    *             ",
        "    *             ",
        "   ****           ",
        "  ******          ",
        "******************",
        ""
    },
    {
        "                  ",
        "          *       ",
        "         ****     ",
        "  *************   ",
        "******************",
        ""
    }

};

Decors::Decors( void ): AEntity(){
    int number;

    number = std::rand() % 4;
    _sprite[0] = spritePool[number][0];
    _sprite[1] = spritePool[number][1];
    _sprite[2] = spritePool[number][2];
    _sprite[3] = spritePool[number][3];
    _sprite[4] = spritePool[number][4];
    _sprite[5] = spritePool[number][5];
    _color = COLOR_WHITE;
    _collisionMask = LAND;
    return;
}

Decors::Decors( bool footer, float xPos, float yPos ): AEntity(xPos, yPos){
    int number;

    number = std::rand() % 4;
    Log::instance().logWarning("number =" + spritePool[number][0]);
    _footer = footer;
    _collisionMask = LAND;
    _sprite = new std::string[6];
    _color = COLOR_WHITE;
    if (footer == true){
        _sprite[0] = spritePool[number][0];
        _sprite[1] = spritePool[number][1];
        _sprite[2] = spritePool[number][2];
        _sprite[3] = spritePool[number][3];
        _sprite[4] = spritePool[number][4];
        _sprite[5] = spritePool[number][5];
        _yPos = GameLoop::getBoardHeight() - 6;
    }
    else{
        _sprite[0] = spritePool[number][4];
        _sprite[1] = spritePool[number][3];
        _sprite[2] = spritePool[number][2];
        _sprite[3] = spritePool[number][1];
        _sprite[4] = spritePool[number][0];
        _sprite[5] = spritePool[number][5]; 
        _yPos = 0;    
    }

    return;
}

Decors::Decors(Decors &src){
    _sprite = src.getSprite();
    _sprite= src.getSprite();
    _isAlive= src.isAlive();
    _color= src.getColor();
    _xPos= src.getXPos();
    _yPos= src.getYPos();
    _collisionMask= src.getCollisionMask();
}

Decors::~Decors(void){
    return;
}

Decors &Decors::operator=(Decors const &rhs){
  _sprite = rhs.getSprite();
  _isAlive= rhs.isAlive();
  _color= rhs.getColor();
  _xPos= rhs.getXPos();
  _yPos= rhs.getYPos();
  _collisionMask= rhs.getCollisionMask();
    return *this;
}

void Decors::onCollision(AEntity *collider){
	return;
}

void	Decors::update(void)
{
	_xPos -= 10 * Time::getDeltaTime();
}