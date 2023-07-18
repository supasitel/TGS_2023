#include "main_scene.h"
#include "../../../game_manager.h"
#include "../../../unit_manager/unit_manager.h"

//コンストラクタ
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent,"MainScene")
{
}

//初期化
void CMainScene::Initialize(void)
{
	aqua::CreateGameObject<CUnitManager>(this);
}

//更新
void CMainScene::Update(void)
{
}
