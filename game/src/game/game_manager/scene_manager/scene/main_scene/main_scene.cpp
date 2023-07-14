#include "main_scene.h"
#include "../../../game_manager.h"

CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent,"MainScene")
{
}

void CMainScene::Initialize(void)
{
	aqua::CreateGameObject<CTargetManager>(this);
	CTargetManager* target = (CTargetManager*)aqua::FindGameObject("TargetManager");

	target->Create(TARGET_ID::WRONG_TARGET);

	IGameObject::Initialize();

	m_State=STATE::START;
}

void CMainScene::Update(void)
{
}
