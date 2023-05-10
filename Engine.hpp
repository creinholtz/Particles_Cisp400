#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <ctime>
#include "Particle.hpp"

using namespace sf;
using namespace std;

class Engine
{
	private:
		RenderWindow m_Window;
		vector<Particle> m_particles;
		void input();
		void update(float dtAsSeconds);
		void draw();

	public:
		Engine();
		void run();
};

#endif