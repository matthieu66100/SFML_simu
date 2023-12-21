
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