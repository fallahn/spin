/*********************************************************************
Matt Marchant 2016
http://trederia.blogspot.com

SpIn - Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.
2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#include <SoundPlayer.hpp>

namespace
{
    float volume = 60.f;

    const std::size_t maxSounds = 160u;
}

SoundPlayer::SoundPlayer()
{
    m_soundBuffers.insert(std::make_pair(Shot, sf::SoundBuffer()));
    m_soundBuffers[Shot].loadFromFile("assets/sounds/shot.wav");
    m_soundBuffers.insert(std::make_pair(ShipHit, sf::SoundBuffer()));
    m_soundBuffers[ShipHit].loadFromFile("assets/sounds/ship_hit.wav");
    m_soundBuffers.insert(std::make_pair(InvaderHit, sf::SoundBuffer()));
    m_soundBuffers[InvaderHit].loadFromFile("assets/sounds/invader_hit.wav");
    m_soundBuffers.insert(std::make_pair(ExtendedPlay, sf::SoundBuffer()));
    m_soundBuffers[ExtendedPlay].loadFromFile("assets/sounds/extended_play.wav");
    m_soundBuffers.insert(std::make_pair(Invader0, sf::SoundBuffer()));
    m_soundBuffers[Invader0].loadFromFile("assets/sounds/inv01.wav");
    m_soundBuffers.insert(std::make_pair(Invader1, sf::SoundBuffer()));
    m_soundBuffers[Invader1].loadFromFile("assets/sounds/inv02.wav");
    m_soundBuffers.insert(std::make_pair(Invader2, sf::SoundBuffer()));
    m_soundBuffers[Invader2].loadFromFile("assets/sounds/inv03.wav");
    m_soundBuffers.insert(std::make_pair(Invader3, sf::SoundBuffer()));
    m_soundBuffers[Invader3].loadFromFile("assets/sounds/inv04.wav");
    m_soundBuffers.insert(std::make_pair(MotherShip, sf::SoundBuffer()));
    m_soundBuffers[MotherShip].loadFromFile("assets/sounds/mothership_hit.wav");
}

//public
void SoundPlayer::update()
{
    m_sounds.remove_if([](const sf::Sound& s) {return (s.getStatus() == sf::Sound::Stopped); });
}

void SoundPlayer::play(SoundPlayer::ID id)
{
    if (m_soundBuffers.count(id) > 0
        && m_sounds.size() < maxSounds)
    {
        m_sounds.emplace_back();
        m_sounds.back().setBuffer(m_soundBuffers[id]);
        m_sounds.back().setVolume(volume);
        m_sounds.back().play();
    }
}