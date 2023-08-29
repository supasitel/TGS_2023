#include "main_scene.h"
#include "../../../unit/unit.h"
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
	//タイマーの生成
	(CTime*)aqua::CreateGameObject<CTime>(this);

	//不正解ターゲットを10体生成
	for (int i = 0; i < 10; ++i)
	{
		(CWrongTarget*)aqua::CreateGameObject<CWrongTarget>(this);
	}

	//正解ターゲットの生成
	(CCurrentTarget*)aqua::CreateGameObject<CCurrentTarget>(this);

	IGameObject::Initialize();
}

//更新
void CMainScene::Update(void)
{
	IGameObject::Update();
}
