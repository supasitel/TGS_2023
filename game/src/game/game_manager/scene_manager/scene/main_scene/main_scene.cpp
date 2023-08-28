#include "main_scene.h"
#include "../../../unit_manager/unit_manager.h"
#include "game/game_manager/game_manager.h"
#include "../../../target_manager/target/current_target/current_target.h"
#include "../../../target_manager/target/wrong_target/wrong_target.h"

//コンストラクタ
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent, "MainScene")
{
}

//初期化
void CMainScene::Initialize(void)
{
	//CUnitManager* um = (CUnitManager*)aqua::CreateGameObject<CUnitManager>(this);
	(CTime*)aqua::CreateGameObject<CTime>(this);

	//不正解ターゲットを10体生成
	for (int i = 0; i < 10; ++i)
	{
		(CWrongTarget*)aqua::CreateGameObject<CWrongTarget>(this);
		/*um->Create(CUnitManager::UNIT_ID::WRONG);*/
	}

	(CCurrentTarget*)aqua::CreateGameObject<CCurrentTarget>(this);
	//um->Create(CUnitManager::UNIT_ID::CURRENT);

	IGameObject::Initialize();
}

//更新
void CMainScene::Update(void)
{
	if (!FindChild("CurrentTarget"))
	{
		if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
		{
			Change(SCENE_ID::CLEAR);
		}
	}

	IGameObject::Update();
}
