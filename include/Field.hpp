#ifndef FIELD_HPP
#define FIELD_HPP

#include "Entity.hpp"
#include "SFML/Graphics.hpp"

class Field : public Entity
{
    private:
        int posX;
        int posY;

    public :

        Field(int x,int y);
        
        void update(long dT);
        void render(sf::RenderWindow& window); 
       



};

#endif