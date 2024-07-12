#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(LevelInfoLayer) {
	struct Fields {
		bool m_buttonInitialized = false;
	};
	void tryCloneLevel(CCObject* p0) {
		this->confirmClone(p0);
	}
	bool init(GJGameLevel* level, bool challenge) {
		if(!LevelInfoLayer::init(level, challenge)) return false;
		if(level->m_levelNotDownloaded) {		
			if(!this->m_cloneBtn->isVisible()) {
				this->m_cloneBtn->setVisible(true);
			}
			if(!this->m_cloneBtn->isEnabled()) {
				this->m_cloneBtn->setEnabled(true);
			}
			this->m_cloneBtn->setSprite(CCSprite::createWithSpriteFrameName("GJ_duplicateBtn_001.png"));
			m_fields->m_buttonInitialized = true;
		}
		return true;
	}
	void levelDownloadFinished(GJGameLevel* p0) {
		LevelInfoLayer::levelDownloadFinished(p0);
		if(!m_fields->m_buttonInitialized) {
			if(this->m_cloneBtn == nullptr) return;
			if(!this->m_cloneBtn->isVisible()) {
				this->m_cloneBtn->setVisible(true);
			}
			if(!this->m_cloneBtn->isEnabled()) {
				this->m_cloneBtn->setEnabled(true);
			}
			this->m_cloneBtn->setSprite(CCSprite::createWithSpriteFrameName("GJ_duplicateBtn_001.png"));
		}
	}
};