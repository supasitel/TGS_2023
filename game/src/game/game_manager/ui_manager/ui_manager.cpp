#include "ui_manager.h"

const std::string IUIManager::m_ui_category = "UIManager";	//カテゴリー

//コンストラクタ
IUIManager::IUIManager(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent,name,m_ui_category)
{
}

//初期化
void IUIManager::Initialize(void)
{
}
