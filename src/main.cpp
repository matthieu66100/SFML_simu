#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

unordered_map<string, float> planetSize{
    {"sun"      ,1391400/10000},
    {"jupiter"  ,142984/10000},
    {"saturne"  ,120536/10000},
    {"uranus"   ,51118/1000},
    {"neptune"  ,49528/1000},
    {"earth"    ,12756/1000},
    {"venus"    ,12104/1000},
    {"mars"     ,6792/1000},
    {"mercure"  ,487/100}
};
unordered_map<string, int> planetDistance{
    {"neptune",   4495100000/500000},
    {"uranus",    2872500000/500000},
    {"saturne",   1433500000/500000},
    {"jupiter",   778600000/500000},
    {"mars",      227900000/500000},
    {"earth",     149600000/500000},
    {"venus",     108200000/500000},
    {"mercure",   57900000/500000}
};
unordered_map<string, int> orbitDistance{
{"neptune",170},
{"uranus",225},
{"saturne",300},
{"jupiter",400},
{"mars",500},
{"earth",600},
{"venus",700},
{"mercure",900},
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
        SolarSystemSim(int s_width, int s_height){
            windowWidth = s_width;
            windowHeight = s_height;
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
