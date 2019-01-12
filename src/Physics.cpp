#include "Physics.hpp"

Physics::Physics( void ){
  return;
}

Physics::Physics( EntitiesList *list){
  _list = list;
  return;
}

Physics::Physics( Physics const & src ){
  _list = src.getlist();
  return;
}

Physics::~Physics( void ){
  return;
}

Physics &Physics::operator=(Physics const & rhs){
  _list = rhs.getList();
  return *this;
}

EntitiesList *Physics::getList( void ){
  return this->_list;
}



bool checkCollisions(AEntity *entity1, AEntity *entity2){
  while ( )
  if (ne sont pqs qu meme endroit){
    return false;
  }
  return true;
}


void Physics::checkMaskCollisions( void ){
    EntityLink    list1;
    EntityLink    list2;
    AEntity       *entity1;
    AEntity       *entity2;
    Collision     mask1;
    Collision     mask2;
    bool          res;

    list1 = _list.getList();
    entity1 = list1->entity
    while (list1->next != NULL){
        mask1 = entity1->getCollisionMask();
        list2 = &list1->next;
        entity2 = list2->entity;
        while (entity2 != NULL){
          mask2 = entity2->getCollisionMask();
          if (mask1 & mask2){
            res = checkCollisions(entity1, entity2);
            if (res == true ){
              entity1->setNotAlive();
              entity2->setNotAlive();
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
