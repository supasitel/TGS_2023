#include "main_scene.h"
#include "../../../game_manager.h"

//コンストラクタ
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent,"MainScene")
{
}

//初期化
void CMainScene::Initialize(void)
{
	(CTarget*)aqua::CreateGameObject<CTarget>(this);
	(CEnemy*)aqua::CreateGameObject<CEnemy>(this);
	(CScore*)aqua::CreateGameObject<CScore>(this);
	(CTime*)aqua::CreateGameObject<CTime>(this);

	IGameObject::Initialize();
}

//更新
void CMainScene::Update(void)
{
	IGameObject::Update();
}

//描画
void CMainScene::Draw(void)
{
	IGameObject::Draw();
}

//解放
void CMainScene::Finalize(void)
{
	IGameObject::Finalize();
}
