#include "main_scene.h"
#include "../../../unit_manager/unit_manager.h"

//コンストラクタ
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent, "MainScene")
{
}

//初期化
void CMainScene::Initialize(void)
{
	CUnitManager* um = (CUnitManager*)aqua::CreateGameObject<CUnitManager>(this);

	//不正解ターゲットを10体生成
	for (int i = 0; i < 10; ++i)
	{
		um->Create(CUnitManager::UNIT_ID::WRONG);
	}

	um->Create(CUnitManager::UNIT_ID::CURRENT);

	IGameObject::Initialize();
}

//更新
void CMainScene::Update(void)
{
	IGameObject::Update();
}
