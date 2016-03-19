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

#ifndef SP_DISPLAY_HPP_
#define SP_DISPLAY_HPP_

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <array>

class Display final : public sf::Drawable
{
public:
    Display();
    ~Display() = default;

    Display(const Display&) = delete;
    Display& operator = (const Display&) = delete;

    void updateBuffer(const std::uint8_t*);

private:
    sf::Texture m_baseTexture;
    sf::Texture m_overlayTexture;
    sf::Texture m_backgroundTexture;
    std::array<sf::Vertex, 4u> m_vertexArray;
    sf::Shader m_blendShader;

    std::array<std::uint8_t, 256 * 224 * 4> m_buffer; //using RGBA texture in SFML so w x h x bpp

    mutable sf::RenderTexture m_postBuffer;
    sf::Sprite m_postSprite;
    sf::Shader m_postShader;

    void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

#endif //SP_DISPLAY_HPP_