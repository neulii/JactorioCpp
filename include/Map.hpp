#ifndef MAP_HPP
#define MAP_HPP

#include "Entity.hpp"
#include "Field.hpp"


class Map : public Entity
{
	private:
		sf::Vector2i mapSize;			//size of the map
		sf::Vector2i fieldSize;			//size of the Fields	
	
		sf::Vector2i mapPosition;		//the Position of the Map

		std::vector<Field*> fields;		//all fields saved here
		
		std::string mapString;			//mapstring for generating map

		//for calculating Coords to LineCoords
		static int CoordToLine(int x, int y, int width, int height);
		static sf::Vector2i LineToCoord(int lineCoord, int width, int height);
		
	public:
		//generate map with string
		Map(sf::Vector2i mapSize, sf::Vector2i fieldSize, sf::Vector2i mapPosition, std::string mapString);

		//generate blank map	
		Map(sf::Vector2i mapSize, sf::Vector2i fieldSize, sf::Vector2i mapPosition);
		
	
		void generateMap();
		void generateMap(std::string mapString);

		void render(sf::RenderWindow& window);
		void update(long dT);
	
	


};


#endif // !MAP_HPP
