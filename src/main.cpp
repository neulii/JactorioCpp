#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include <vector>
#include "FieldTypes.hpp"
#include "Map.hpp"

//Entity Functions
void render(sf::RenderWindow& window);
void update(long dT);

void loadRessources();
void loadFieldTextures(std::vector<sf::Texture> textures);

//Global variables

sf::Vector2i mapSize(10, 4);
sf::Vector2i fieldSize(100, 100);
sf::Vector2i mapPosition(0, 0);

int windowWidth = mapSize.x * fieldSize.x;
int windowHeight = mapSize.y * fieldSize.y;

std::vector<sf::Texture> fieldTextures;


std::vector<Entity*> entitys;

std::string mapString =
    "0000000000"
    "1111111111"
    "1111111111"
    "1111111111";

Map* map = new Map(mapSize, fieldSize, mapPosition ,mapString);
//Map* map = new Map(mapSize, fieldSize, mapPosition);



//main Function
int main()
{
    loadRessources();
    entitys.push_back(map);
    map->generateSprites(fieldTextures);


    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {

               
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				std::cout << "Exiting" << std::endl;
				window.close();
			}
        }

        //long dT = 1;

        sf::Time time = clock.getElapsedTime(); 
        clock.restart(); 
        update(time.asMicroseconds());
    
        render(window);
        
    }

    return 0;
}

void render(sf::RenderWindow& window)
{
        window.clear(sf::Color::Blue);  //clear window
        //render here all stuff
       

        //paint all objects from Game
        for(Entity* e : entitys)
        {
            e->render(window);
        }
        
        window.display();
}

void update(long dT)
{
    for(Entity* e: entitys)
    {
        e->update(dT);

    } 
    
    //    std::cout << dT << std::endl;

}

//Load all resources
void loadRessources()
{
    loadFieldTextures(fieldTextures);


}


//load Field Textures
void loadFieldTextures(std::vector<sf::Texture> textures) {

    sf::Texture tex;


    tex.loadFromFile("res/grass.png");
    //textures.push_back(tex);
    /*
    tex.loadFromFile("res/stone.png");
    textures.push_back(tex);
    tex.loadFromFile("res/stone.png");
    textures.push_back(tex);

    tex.loadFromFile("res/stone.png");
    textures.push_back(tex);

    tex.loadFromFile("res/stone.png");
    textures.push_back(tex);
    */




}

