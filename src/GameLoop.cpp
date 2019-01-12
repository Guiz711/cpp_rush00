#include "GameLoop.hpp"

GameLoop::GameLoop( void ){
return;
}

GameLoop::GameLoop( GameLoop const & src ){
  _list = src.getList();
  return;
}

GameLoop::~GameLoop( void ){
  return;
}

GameLoop &GameLoop::operator=(const GameLoop &rhs){
  _list = rhs.getList();
  return *this;
}


EntitiesList *GameLoop::getList( void ) const{
  return _list;
}

void GameLoop::_update( void ){
  EntityLink *tmp;

  tmp = _list->getList();
  while (tmp->next != NULL){
  //  tmp->entity->update();
    tmp = tmp->next;
  }
//  tmp->entity->update();
  return;
}

void GameLoop::checkAlive( void ){
  EntityLink  tmp;
  EntityLink  tmp2;

  tmp = *(_list->getList());
  while (tmp.next != NULL){
    tmp2 = *(tmp.next);
    if (tmp.entity->isAlive() == false){
      _list->removeEntity(&tmp);
    }
    tmp = tmp2;
  }
  if (tmp.entity->isAlive() == false){
    _list->removeEntity(&tmp);
  }
  return;
}

void GameLoop::startLoop( void ){
    while(1){
      _time.updateTime();
      _inputs.updateInputs();
      _update();
      _physics.setList(_list);
      _physics.checkCollisions();
      checkAlive();
      _renderer.renderScreen(_list->getList());
    }
    _list->destroyList();
    return;
}
