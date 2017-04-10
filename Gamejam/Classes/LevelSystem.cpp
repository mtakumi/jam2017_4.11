#include "LevelSystem.h"
//#include "cocostudio/CocoStudio.h"
//#include "ui/CocosGUI.h"

USING_NS_CC;

//using namespace cocostudio::timeline;

// creat�֐�
LevelSystem* LevelSystem::create()
{
	LevelSystem *pRet = new(std::nothrow) LevelSystem(); 
	if (pRet && pRet->init()) 
	{ 
		pRet->autorelease(); 
		return pRet; 
	} 
	else 
	{ 
		delete pRet; 
		pRet = nullptr; 
		return nullptr; 
	} 
}

// init�֐�
bool LevelSystem::init()
{
	if (!Node::init())
	{
		return false;
	}

	m_level_info[4] = { 0 };

	m_level = 0;

	return true;
}

// ���x���̏����Z�b�g����֐�
void LevelSystem::set_level(int lv, int count, float beatspd)
{
	m_level = lv;
	m_level_info[m_level].count = count;
	m_level_info[m_level].press_time = beatspd;
}


// ���x����ϓ�����֐�
void LevelSystem::up_level()
{
	m_level++;
}

// ���x����ϓ�����֐�
void LevelSystem::down_level()
{
	m_level--;
}


// ���݂̃��x�����擾����֐�
LEVEL LevelSystem::get_level() const
{
	return m_level_info[m_level];
}
