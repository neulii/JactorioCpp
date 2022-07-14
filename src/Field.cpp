#include "Field.hpp"

Field::Field(int x, int y, int width, int height)
{
    this->posX = x;
    this->posY = y;
    this-> width = width;
    this-> height = height;

    field = sf::RectangleShape(sf::Vector2f(width,height));
    field.setPosition(posX,posY);

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