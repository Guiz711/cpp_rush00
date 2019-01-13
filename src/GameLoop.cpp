#include "GameLoop.hpp"
#include "Player.hpp"

EntitiesList *GameLoop::_list = NULL;

GameLoop::GameLoop( void ) {
	_list = new EntitiesList();
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
	while (tmp != NULL){
	 	tmp->entity->update();
		tmp = tmp->next;
	}
	//  tmp->entity->update();
	return;
}

void GameLoop::checkAlive( void ){
	EntityLink  *tmp;
	EntityLink  *tmp2;

	tmp = _list->getList();
	while (tmp != NULL){
		tmp2 = tmp->next;
		if (tmp->entity->isAlive() == false){
		_list->removeEntity(tmp);
		}
		tmp = tmp2;
	}
	// if (tmp->entity->isAlive() == false){
	// 	_list.removeEntity(tmp);
	// }
	return;
}

void GameLoop::startLoop( void ){
	Player *player = new Player();
	_list->addEntity(player);
	while(1) {
		_time.updateTime();
		_inputs.updateInputs();
		_update();
		_physics.setList(_list);
		_physics.checkCollisions();
		checkAlive();
		_renderer.renderScreen(_list->getList());
	}
	// delete _list;
	return;
}

void	GameLoop::addEntity(AEntity *entity)
{
	if (!_list)
	{
		Log::instance().logError("Entities List not initialised.");
		return;
	}

	_list->addEntity(entity);
}
