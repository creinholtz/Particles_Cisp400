#ifndef ENGINE_HPP
#define ENGINE_HPP
#endif

#include "Particle.hpp"
#include "SFML/include/SFML/System.hpp"
#include "SFML/include/SFML/Audio.hpp"
#include "SFML/include/SFML/Graphics.hpp"
#include <ctime>


using namespace sf;
using namespace std;

class Engine
{
private:
	// A regular RenderWindow
	RenderWindow m_Window;

	//vector for Particles
	vector<Particle> m_particles;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();
};