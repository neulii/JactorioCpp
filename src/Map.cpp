#include "Map.hpp"

Map::Map(int mapWidth, int mapHeight, int fieldWidth, int fieldHeight)
{
	this->mapHeight = mapHeight;
	this->mapWidth = mapWidth;

	this->fieldWidth = fieldWidth;
	this->fieldHeight = fieldHeight;

	//generate Map

	for (int i = 0; i < mapWidth * mapHeight; i++)
	{
		//calculate Position of new Field

		fields.at(i) = new Field()
	}


}

void Map::render(sf::RenderWindow& window)
{
	

}

void Map::update(long dT)
{

}

//calculates the LineCoordinate to LineCoord because vectorindex
sf::Vector2i Map::LineToCoord(int lineCoord, int width, int height)
{
	sf::Vector2i coord;
	int x = 0;
	int y = 0;

	y = lineCoord % width;
	x = lineCoord - y * x;

	coord.x = x;
	coord.y = y;

	return coord;
}

//calculates the Coordinaten to LineCoord because vectorindex
int Map::CoordToLine(int x, int y, int width, int height)
{
	int lineCoord = 0;
	lineCoord = y * width + x;

	return lineCoord;
}

