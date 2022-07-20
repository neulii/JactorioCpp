#include "Map.hpp"

Map::Map(sf::Vector2i mapSize, sf::Vector2i fieldSize, sf::Vector2i mapPosition)
{
	this->mapSize = mapSize;
	this->fieldSize = fieldSize;
	this->mapPosition = mapPosition;
	this->mapString = "XX";

	std::cout << "3 parameter konstruktor -> " << this->mapString << std::endl;


	generateMap(this->mapString);


		

}
Map::Map(sf::Vector2i mapSize, sf::Vector2i fieldSize, sf::Vector2i mapPosition, std::string mapString)
	:Map(mapSize,fieldSize,mapPosition)
{


	this->mapString = mapString;
	std::cout << "4 parameter konstruktor -> " << this->mapString << std::endl;
	generateMap(this->mapString);
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
	x = lineCoord % width;

	y = lineCoord / width;
	//x = lineCoord - y * x;

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

//generate blank map
void Map::generateMap()
{
	generateMap("");
}

//generate Map with mapstring
void Map::generateMap(std::string mapString)
{
	//first check if Mapstring is valid
	long mustFields = (mapSize.x) * (mapSize.y);
	std::cout << "fields must have: " << mustFields << " /   Fields have: " << mapString.size();
	
	if (mustFields != mapString.size())
	{
		std::cout << "MapString passt nicht zur Groessenangabe!! -> map wird nicht generiert!!" << std::endl;
		return;
	}

		for (int i = 0; i < mapSize.x * mapSize.y; i++)
		{
			//calculate Position of new Field
			sf::Vector2i tempCoord = LineToCoord(i, mapSize.x, mapSize.y);

			//debug-output
			//std::cout << "line: " << tempCoord.x << " / " << tempCoord.y << std::endl;

			int tempX = 0;
			int tempY = 0;

			//xCoordinate	
			tempX = tempCoord.x * fieldSize.x + mapPosition.x;
			//yCoordinate
			tempY = tempCoord.y * fieldSize.y + mapPosition.y;
			Field* f;

			if (mapString.empty())
			{

				f = new Field(tempX, tempY, fieldSize.x, fieldSize.y);
					
			
			}
			else
			{
				FieldType tempType = FieldType::Blank;
				int type = mapString.at(i) + 48;
				std::cout << mapString.at(i) << "   " << type << std::endl;

				f = new Field(tempX, tempY, fieldSize.x, fieldSize.y, tempType);
				
			}
			//temporary set color for testing	
			if(!mapString.empty())
				f->setColor(sf::Color(i * 2, 255 - i * 2, 0));

			fields.push_back(f);

		}


}
