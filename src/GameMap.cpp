#include "GameMap.hpp"

GameMap::GameMap(sf::Vector2i mapSize, sf::Vector2i tileSize)
{
	generateMap(mapSize, tileSize);

}

GameMap::GameMap(sf::Vector2i mapSize, sf::Vector2i tileSize, String mapString)
{

	generateMap(mapSize, tileSize, mapString)
}

void GameMap::generateMap(sf::Vector2i mapSize, sf::Vector2i tileSize)
{
	//Todo generate empty map

}

void GameMap::generateMap(sf::Vector2i mapSize, sf::Vector2i tileSize, String mapString)
{
	generateMap(mapSize, tileSize);
	//Todo generate Map

}
