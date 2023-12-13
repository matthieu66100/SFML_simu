#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


unordered_map<string, float> planetSize
{
    {"sun"      ,1391400/10000},
    {"jupiter"  ,142984/1000},
    {"saturne"  ,120536/1000},
    {"uranus"   ,51118/1000},
    {"neptune"  ,49528/1000},
    {"earth"    ,12756/1000},
    {"venus"    ,12104/1000},
    {"mars"     ,6792/1000},
    {"mercure"  ,487/10009}
};
unordered_map<string, int> planetDistance{
    {"neptune",   4495100000},
    {"uranus",    2872500000},
    {"saturne",   1433500000},
    {"jupiter",   778600000},
    {"mars",      227900000},
    {"earth",     149600000},
    {"venus",     108200000},
    {"mercure",   57900000}
};

class CelestialBody
{
    private:
        CircleShape shape;
        Vector2f position;
        Vector2f velocity;

    public:
    CelestialBody(float radius, Vector2f position, Vector2f velocity, Color color)
    {
        shape.setRadius(radius);
        shape.setFillColor(color);
        position.x = position.x - radius;
        position.y = position.y - radius;
        shape.setPosition(position);
        this->position;
        this->velocity;
    }
    void update(float deltaTime){
        position += velocity * deltaTime;
    }
    void draw(RenderWindow& window){
        window.draw(shape);
    }
};

class SolarSystemSim
    {
    private:
        RenderWindow window;
        int windowWidth;
        int windowHeight;

        vector<CelestialBody> celestialBodies; // Liste des corps celestes
    public:
        // Creator
        SolarSystemSim(int width, int height){
            windowWidth = width;
            windowHeight = height;
            window.create(VideoMode(windowWidth, windowHeight), "Solar System Simulator");
        }

        // Permet d'ajouter au vecteur les corps celestes qui sont appelés
        void addCelestialBody(CelestialBody body){
            celestialBodies.push_back(body);
        }
        
        void runSimulation() {
            Clock clock;
    
            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed)
                        window.close();
                }
    
                float deltaTime = clock.restart().asSeconds();
    
                window.clear();
    
                for (auto& body : celestialBodies) {
                    body.update(deltaTime);
                    body.draw(window);
                }
    
                window.display();
            }
        }

};

int main(){


    SolarSystemSim simulator(1500, 1000);

    CelestialBody sun(planetSize["sun"], Vector2f(1500/2,1000/2), Vector2f(0,0), Color::Yellow);
    CelestialBody earth(planetSize["earth"], Vector2f(400,300), Vector2f(0,0), Color::Blue);
    CelestialBody mars(planetSize["mars"], Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody venus(planetSize["venus"], Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody uranus(planetSize["uranus"], Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody jupiter(planetSize["jupiter"], Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody mercure(planetSize["mercure"], Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody saturne(planetSize["saturne"], Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody neptune(planetSize["neptune"], Vector2f(800,300), Vector2f(0,0), Color::Red);

    simulator.addCelestialBody(sun);
    simulator.addCelestialBody(earth);
    simulator.addCelestialBody(mars);

    simulator.runSimulation();

    return 0;
}
