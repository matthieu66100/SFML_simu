#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


int init_planets(RenderWindow window, CircleShape sol, CircleShape terra, CircleShape venus, CircleShape mars){


    return 1;
}

int main(int argc, char const *argv[])
{
    // Création 
    RenderWindow window(VideoMode(1500, 1000), "Simulation");
    // Define Planets
    CircleShape sol;
    CircleShape terra;
    CircleShape venus;
    CircleShape mars;

///___________________________________________________________///
    int windowCX = window.getSize().x/2;
    int windowCY = window.getSize().y/2;

    sol.setRadius(100.f);
    sol.setPosition(float(windowCX) - sol.getRadius()/2, float(windowCY) - sol.getRadius()/2);
    sol.setFillColor(Color::Yellow);

    terra.setRadius(40.f);
    terra.setPosition(30.f,30.f);
    terra.setFillColor(Color::Green);

    venus.setRadius(40.f);
    venus.setPosition(30.f,30.f);
    venus.setFillColor(Color::Green);

    mars.setRadius(40.f);
    mars.setPosition(30.f,30.f);
    mars.setFillColor(Color::Green);
///___________________________________________________________///


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sol);
        window.draw(terra);

        window.display();
    }

    return 0;
}