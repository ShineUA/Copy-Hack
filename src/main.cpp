#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* level, bool challenge) {
		if(!LevelInfoLayer::init(level, challenge)) return false;		
		if(!this->m_cloneBtn->isVisible()) {
			this->m_cloneBtn->setVisible(true);
		}
		if(!this->m_cloneBtn->isEnabled()) {
			this->m_cloneBtn->setEnabled(true);
		}
		this->m_cloneBtn->setSprite(CCSprite::createWithSpriteFrameName("GJ_duplicateBtn_001.png"));
		return true;
	}
	void tryCloneLevel(CCObject* p0) {
		this->confirmClone(p0);
	}
};