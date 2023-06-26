#include "enemy.h"

const int CEnemy::m_width = 64;	//幅
const int CEnemy::m_height = 64;	//高さ

//コンストラクタ
CEnemy::CEnemy(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Enemy")
{
}

//初期化
void CEnemy::Initialize(void)
{
	m_Enemy.Create("data\\abe.png");
	m_Enemy.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Enemy.GetTextureWidth() / 2.0f;
	m_Enemy.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_Enemy.GetTextureHeight() / 2.0f;
}

//更新
void CEnemy ::Update(void)
{
}

//描画
void CEnemy ::Draw(void)
{
	m_Enemy.Draw();
}

//解放
void CEnemy ::Finalize(void)
{
	m_Enemy.Delete();
}
