#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity
{
	
	
	public:
		virtual void update(long dT) = 0;
		virtual void render(sf::RenderWindow& window) = 0;

};




#endif
