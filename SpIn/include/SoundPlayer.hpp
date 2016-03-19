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

#ifndef SP_SOUNDPLAYER_HPP_
#define SP_SOUNDPLAYER_HPP_

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include <cstdint>
#include <map>
#include <list>

class SoundPlayer final
{
public:
    using ID = std::int32_t;

    enum
    {
        Shot = 2,
        ShipHit = 3,
        InvaderHit = 4,
        ExtendedPlay = 5,

        Invader0 = 10,
        Invader1 = 11,
        Invader2 = 12,
        Invader3 = 13,
        MotherShip = 14
    };

    SoundPlayer();
    ~SoundPlayer() = default;
    SoundPlayer(const SoundPlayer&) = delete;
    SoundPlayer& operator = (const SoundPlayer&) = delete;

    void update();
    void play(ID);

private:

    std::map<ID, sf::SoundBuffer> m_soundBuffers;
    std::list<sf::Sound> m_sounds;
};

#endif //SP_SOUNDPLAYER_HPP_