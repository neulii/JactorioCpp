#ifndef MAP_HPP
#define MAP_HPP

#include "Entity.hpp"
#include "Field.hpp"


class Map : public Entity
{
	private:
		int mapHeight;
		int mapWidth;

		int fieldHeight;
		int fieldWidth;
		
		std::vector<Field*> fields;
			
	public:
		Map(int mapWidth, int mapHeight, int fieldWidth, int fieldHeight);
		
		void render(sf::RenderWindow& window);
		void update(long dT);
		


};


#endif // !MAP_HPP
