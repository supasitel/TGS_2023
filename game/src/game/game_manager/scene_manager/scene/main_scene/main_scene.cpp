#include "main_scene.h"
#include "../../../enemy/enemy.h"

//コンストラクタ
CMainScene::CMainScene(aqua::IGameObject* parent)
	:IScene(parent,"MainScene")
{
}

//初期化
void CMainScene::Initialize(void)
{
	m_GBackGround.Create("data\\magic_circle.png");
	m_GBackGround.position = aqua::CVector2::ZERO;

	CEnemy* enemy = (CEnemy*)aqua::CreateGameObject<CEnemy>(this);
}

//更新
void CMainScene::Update(void)
{
}

//描画
void CMainScene::Draw(void)
{
	m_GBackGround.Draw();
}

//解放
void CMainScene::Finalize(void)
{
	m_GBackGround.Delete();
}
