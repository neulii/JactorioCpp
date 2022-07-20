#include "Field.hpp"

//constructor for blank field
Field::Field(int x, int y, int width, int height)
    :Field(x,y,width,height, FieldType::Blank)
{
   

}

//constructor for field
Field::Field(int x, int y, int width, int height, FieldType type)
{
  
    this->posX = x;
    this->posY = y;
    this->width = width;
    this->height = height;

    field = sf::RectangleShape(sf::Vector2f(width, height));
    field.setPosition(posX, posY);
    
    this->type= type;


    switch (this->type)
    {
    case FieldType::Blank:
        break;

    case FieldType::Grass:
        break;
    
    case FieldType::Stone:
        break;
     
    case FieldType::Water:
        break;
    
    
    default:
        break;
    }








}

void Field::render(sf::RenderWindow& window)
{
    window.draw(field);

}

void Field::update(long dT)
{
}

void Field::setColor(sf::Color color)
{
    field.setFillColor(color);
}

int Field::getX()
{
	return this->posX;
}

int Field::getY()
{
	return this->posY;
}

void Field::toConsole()
{
    std::cout << "X: " << posX <<  "  Y: " << +posY << std::endl;
}