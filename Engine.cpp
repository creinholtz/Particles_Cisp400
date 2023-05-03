#include <iomanip>
#include "Engine.hpp"

Engine::Engine()
{
  size_t height = VideoMode::getDesktopMode().height;
  size_t width = VideoMode::getDesktopMode().width;
  
  RenderWindow m_Window(VideoMode(height, width), "Particles", Style::Default);
}

void Engine::run()
{
  clock_t clock = std::clock();

  while(m_Window.isOpen())
  {
    input();
    update((std::clock() - clock) / CLOCKS_PER_SEC);
    draw();
  }
}

void Engine::input()
{
  Event event;
  while(m_Window.pollEvent(event))
  {
    if(event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
      m_Window.close();
    else if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
    {
      for(int i = 0; i <  5; i++)
      {
        Particle particle(m_Window, rand() % 25 + 25, Vector2i(event.mouseButton.x, event.mouseButton.y));
        m_particles.push_back(particle);
      }
    }
  }
}

void Engine::update(float dtAsSeconds)
{
  for(int i = 0; i < m_particles.size(); i++)
  {
    if(m_particles.at(i).getTTL() > 0)
      m_particles.at(i).update(dtAsSeconds);
    else
      m_particles.erase(m_particles.begin() + i);
  }
}

void Engine::draw()
{
  m_Window.clear();
  for(Particle particle : m_particles)
    m_Window.draw(particle);
  m_Window.display();
}