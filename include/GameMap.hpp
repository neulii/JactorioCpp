#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include <SFML/Graphics.hpp>
#include "FieldTypes.hpp"

class GameMap
{
	private:
	
		sf::Vector2i mapSize;
		sf::Vector2i tileSize;
		
		String mapString;
		vector<GameField*> gameFields;

	public:
		
		GameMap(sf::Vector2i mapSize, sf::Vector2i tileSize )								//Constructor for creating blank map	
		GameMap(sf::Vector2i mapSize, sf::Vector2i tileSize, String mapString); //Constructor for Map with given Mapstring
		
		void generateMap(sf::Vector2i mapSize, sf::Vector2i tileSize);
		void generateMap(sf::Vector2i mapSize, sf::Vector2i tileSize, String mapString);



};




#endif
