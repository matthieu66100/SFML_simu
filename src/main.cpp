#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/const.hpp"
#include "../include/planets.hpp"
#include "../include/simulation.hpp"

using namespace std;
using namespace sf;

int main(){
    int s_width = 2000;
    int s_height = 1000;
    SolarSystemSim simulator(s_width, s_height);

    CelestialBody sun(planetSize["sun"],        Vector2f(s_width/2,1000/2), Vector2f(0,0), Color::Yellow);
    CelestialBody mercure(planetSize["mercure"],Vector2f(s_width/2 - 170,1000/2), Vector2f(0,0), Color::Yellow);
    CelestialBody venus(planetSize["venus"],    Vector2f(s_width/2 - 225,1000/2), Vector2f(0,0), Color::Magenta);
    CelestialBody earth(planetSize["earth"],    Vector2f(s_width/2 - 300,1000/2), Vector2f(0,0), Color::Blue);
    CelestialBody mars(planetSize["mars"],      Vector2f(s_width/2 - 400,1000/2), Vector2f(0,0), Color::Red);
    CelestialBody jupiter(planetSize["jupiter"],Vector2f(s_width/2 - 500,1000/2), Vector2f(0,0), Color::White);
    CelestialBody saturne(planetSize["saturne"],Vector2f(s_width/2 - 600,1000/2), Vector2f(0,0), Color::White);
    CelestialBody uranus(planetSize["uranus"],  Vector2f(s_width/2 - 700,1000/2), Vector2f(0,0), Color::Blue);
    CelestialBody neptune(planetSize["neptune"],Vector2f(s_width/2 - 900,1000/2), Vector2f(0,0), Color::Blue);

    simulator.addCelestialBody(sun);
    simulator.addCelestialBody(mercure);
    simulator.addCelestialBody(venus);
    simulator.addCelestialBody(earth);
    simulator.addCelestialBody(mars);
    simulator.addCelestialBody(jupiter);
    simulator.addCelestialBody(saturne);
    simulator.addCelestialBody(uranus);
    simulator.addCelestialBody(neptune);
    
    simulator.runSimulation();

    return 0;
}
