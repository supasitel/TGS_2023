#include "back_ground.h"

//コンストラクタ
CBackGround::CBackGround(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "BackGround")
{
}

//初期化
void CBackGround::Initialize(void)
{
	//背景
	m_BackGround.Create("data\\main_ground.png");
	m_BackGround.position = aqua::CVector2::ZERO;
}

//描画
void CBackGround::Draw(void)
{
	m_BackGround.Draw();
}

//解放
void CBackGround::Finalize(void)
{
	m_BackGround.Delete();
}
