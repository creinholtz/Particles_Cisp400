#include <iomanip>
#include "Engine.hpp"

Engine::Engine() : m_Window(VideoMode(VideoMode::getDesktopMode().height, VideoMode::getDesktopMode().width), "Particles", Style::Default)
{
}

void Engine::run()
{
  cout << "Starting Particle unit tests..." << endl;
  Particle test(m_Window, 4, {(int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2});
  test.unitTests();
  cout << "Unit tests complete.  Starting engine..." << endl;
  
  clock_t clock = std::clock();
  while(m_Window.isOpen())
  {
    input();
    update((float)(std::clock() - clock) / CLOCKS_PER_SEC);
    clock = std::clock();
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
      int numParticles = rand() % 5 + 5;
      for(int i = 0; i < numParticles; i++)
      {
        Particle particle(m_Window, rand() % 25 + 25, Vector2i(event.mouseButton.x, event.mouseButton.y));
        m_particles.push_back(particle);
      }
    }
  }
}

void Engine::update(float dtAsSeconds)
{
  for (int i = 0; i < m_particles.size();)
    {
    if (m_particles.at(i).getTTL() > 0) {
      m_particles.at(i).update(dtAsSeconds);
      i++;
    } else {
      m_particles.erase(m_particles.begin() + i);
    }
  }
}

void Engine::draw()
{
  m_Window.clear();
  for(Particle particle : m_particles)
    particle.draw(m_Window, RenderStates());
  m_Window.display();
}