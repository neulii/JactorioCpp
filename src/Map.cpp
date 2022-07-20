#include "Map.hpp"
/*
*/
Map::Map(sf::Vector2i mapSize, sf::Vector2i fieldSize, sf::Vector2i mapPosition):
	Map(mapSize, fieldSize, mapPosition,"")
{

}
Map::Map(sf::Vector2i mapSize, sf::Vector2i fieldSize, sf::Vector2i mapPosition, std::string mapString)
{
	this->mapSize = mapSize;
	this->fieldSize = fieldSize;
	this->mapPosition = mapPosition;
	

	this->mapString = mapString;
	generateMap(this->mapString);
	/*
	*/
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
			
			//when no mapstring empty fields are generated
			if (mapString.empty())
			{
				f = new Field(tempX, tempY, fieldSize.x, fieldSize.y);
			
				f->setColor(sf::Color(0,0 , i*20));
			
			}
			else
			{
				//check if string is valid
				long mustFields = (mapSize.x) * (mapSize.y);
	
				if (mustFields != mapString.size())
				{
					std::cout << "MapString passt nicht zur Groessenangabe!! -> map wird nicht generiert!!" << std::endl;
					return;
				}


				int type = mapString.at(i) - 48;

				f = new Field(tempX, tempY, fieldSize.x, fieldSize.y, static_cast<FieldType>(type));
	
				f->setColor(sf::Color( 255-i * 2,0,0 ));
			}
		
			fields.push_back(f);

		}


}
