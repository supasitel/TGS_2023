#include "ui_manager.h"

const std::string IUIManager::m_ui_category = "UIManager";	//�J�e�S���[

//�R���X�g���N�^
IUIManager::IUIManager(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent,name,m_ui_category)
{
}

//������
void IUIManager::Initialize(void)
{
}
