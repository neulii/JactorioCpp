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
	
		//the Position of the Map
		sf::Vector2i mapPosition;

		std::vector<Field*> fields;
			
		//for calculating Coords to LineCoords
		static int CoordToLine(int x, int y, int width, int height);
		static sf::Vector2i LineToCoord(int lineCoord, int width, int height);
		
	public:
		Map(int mapWidth, int mapHeight, int fieldWidth, int fieldHeight, sf::Vector2i mPosition);
		
		void render(sf::RenderWindow& window);
		void update(long dT);
	
	


};


#endif // !MAP_HPP
