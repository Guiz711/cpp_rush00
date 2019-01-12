#include "GameLoop.hpp"

GameLoop::GameLoop( void ){
return;
}

GameLoop::GameLoop( GameLoop const & src ){
  _list = src.getlist();
  return;
}

GameLoop::~GameLoop( void ){
  return;
}

GameLoop::GameLoop &operator=(const GameLoop &rhs){
  _list = rhs.getList();
  return *this;
}


EntitiesList *GameLoop::getList( void ){
  return _list;
}

void GameLoop::_update( void ){
  EntitiesList *tmp;

  while (tmp->next != NULL){
    tmp.update();
    tmp = tmp->next;
  }
  tmp.update();
  return;
}


void GameLoop::_manageEntities( void ){
  return;
}

void GameLoop::startLoop( void ){
    while(1){

    }
    return;
}
