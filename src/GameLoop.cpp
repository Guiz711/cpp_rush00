#include "GameLoop.hpp"

EntitiesList	*GameLoop::_list = NULL;
bool			GameLoop::_running = false;
int				GameLoop::_boardWidth = 0;
int				GameLoop::_boardHeight = 0;

GameLoop::GameLoop( void )
{
	_boardHeight = _renderer.getScreenHeight();
	_boardWidth = _renderer.getScreenWidth();
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
		if (tmp->entity->isAlive() == false
			|| isOutsideMap(tmp->entity->getXPos(), tmp->entity->getYPos())) {
			_list->removeEntity(tmp);
		}
		tmp = tmp2;
	}
	return;
}

void GameLoop::startLoop( void ){
	_list->addEntity(new Game());
	_running = true;
	while(_running) {
		_time.updateTime();
		_inputs.updateInputs();
		_update();
		_physics.setList(_list);
		_physics.checkCollisions();
		checkAlive();
		_renderer.renderScreen(_list->getList());
	}
	_list->destroyList();
	delete _list;
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

bool	GameLoop::isOutsideMap(int x, int y)
{
	if (x < 0 || x >= _boardWidth)
		return true;
	if (y < 0 || y >= _boardHeight)
		return true;
	return false;
}


void	GameLoop::quitGame(void) { _running = false; }

int		GameLoop::getBoardWidth(void) { return _boardWidth; }
int		GameLoop::getBoardHeight(void) { return _boardHeight; }
