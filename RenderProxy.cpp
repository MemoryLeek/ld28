#include "RenderProxy.h"

RenderProxy::RenderProxy(sf::RenderTarget &subject, const sf::Vector2<int> &target)
	: m_subject(subject)
	, m_target(target)
{

}

void RenderProxy::draw(const sf::Drawable &drawable, sf::RenderStates states) const
{
	sf::Transform transform;
	transform.translate(m_target.x, m_target.y);

	states.transform = transform;

	m_subject.draw(drawable, states);
}
