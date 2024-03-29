#pragma once
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\System\Time.hpp>
#include "LinkedList.h"
#include "Observer.h"

class GameState :
	public sf::Drawable
{
	public:
	static enum Event { END };
	typedef Observer<Event, GameState*> Observer;

	private:
	sf::Vector2f mousePos_;
	LinkedList<Observer*> observers_;

	public:
	GameState();
	virtual ~GameState();

	virtual void update(sf::Time const& deltaTime) = 0;
	virtual void restart() = 0;

	virtual void setMousePos(sf::Vector2f const& mousePos);
	sf::Vector2f const& getMousePos() const;

	void addObserver(Observer* observer);
	void notify(Event event);
};



