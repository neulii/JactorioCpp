#include "Map.hpp"

Map::Map(int mapWidth, int mapHeight, int fieldWidth, int fieldHeight, sf::Vector2i mPosition)
{
	this->mapHeight = mapHeight;
	this->mapWidth = mapWidth;

	this->fieldWidth = fieldWidth;
	this->fieldHeight = fieldHeight;
	
	this->mapPosition = mapPosition;

	//generate Map

	for (int i = 0; i < mapWidth * mapHeight; i++)
	{
		//calculate Position of new Field
		sf::Vector2i tempCoord = LineToCoord(i, mapWidth, mapHeight);
	
		int tempX = 0;
		int tempY = 0;
	
		tempX = tempCoord.x * fieldWidth+ mapPosition.x;
		tempY = tempCoord.y * fieldHeight + mapPosition.y;
		
		fields.push_back(new Field(tempX, tempY, tempCoord.x, tempCoord.y));
		
	}


}

void Map::render(sf::RenderWindow& window)
{
	for (Field *f : fields)
	{
		f->render(window);
	}

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

