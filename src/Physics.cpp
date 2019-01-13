#include "Physics.hpp"
#include <string.h>

Physics::Physics( void ){
  return;
}

Physics::Physics( EntitiesList *list){
  _list = list;
  return;
}

Physics::Physics( Physics const & src ){
  _list = src.getList();
  return;
}

Physics::~Physics( void ){
  return;
}

Physics &Physics::operator=(Physics const & rhs){
  _list = rhs.getList();
  return *this;
}

EntitiesList *Physics::getList( void ) const {
  return this->_list;
}

void Physics::setList( EntitiesList *list ){
  _list = list;
  return;
}

bool checkCollision(AEntity *entity1, AEntity *entity2){
  std::string   *sprite1;
  std::string   *sprite2;
  int           xPos1;
  int           xPos2;
  int           yPos1;
  int           yPos2;

  sprite1 = entity1->getSprite();
  sprite2 = entity2->getSprite();
  xPos1 = entity1->getXPos();
  xPos2 = entity2->getXPos();
  yPos1 = entity1->getYPos();
  yPos2 = entity2->getYPos();

  if(!sprite1 || !sprite2)
    return false;

  for (int i1 = 0; sprite1[i1][0]; i1 += 1){
    for (int j1 = 0; sprite1[i1][j1]; j1 += 1){
      for (int i2 = 0; sprite2[i2][0]; i2 += 1){
        for (int j2 = 0; sprite2[i2][j2]; j2 += 1){
          if ((yPos1 + i1 == yPos2 + i2) && (xPos1 + j1 == xPos2 + j2) && (sprite1[i1][j1] != ' ') && (sprite2[i2][j2] != ' '))
            return true;
        }
      }
    }
  }
  return false;
}


void Physics::checkCollisions( void ){
    EntityLink    *list1;
    EntityLink    *list2;
    AEntity       *entity1;
    AEntity       *entity2;
    Collision     mask1;
    Collision     mask2;
    bool          res;

  list1 = _list->getList();
	if (!list1)
		return;
  entity1 = list1->entity;
  while (list1->next != NULL){
      mask1 = entity1->getCollisionMask();
      list2 = list1->next;
      entity2 = list2->entity;
      while (entity2 != NULL){
        mask2 = entity2->getCollisionMask();
         if (!(mask1 & mask2)){
          res = checkCollision(entity1, entity2);
          if (res == true ){
            entity1->onCollision(entity2);
            entity2->onCollision(entity1);
          }
         }
        if (list2->next != NULL){
          list2 = list2->next;
          entity2 = list2->entity;
        }
        else
          entity2 = NULL;
      }
      list1 = list1->next;
      entity1 = list1->entity;
  }
}
