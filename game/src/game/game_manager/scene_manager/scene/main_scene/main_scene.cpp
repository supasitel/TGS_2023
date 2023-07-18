#include "main_scene.h"
#include "../../../game_manager.h"
#include "../../../unit_manager/unit_manager.h"

//�R���X�g���N�^
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent,"MainScene")
{
}

//������
void CMainScene::Initialize(void)
{
	aqua::CreateGameObject<CUnitManager>(this);
}

//�X�V
void CMainScene::Update(void)
{
}
