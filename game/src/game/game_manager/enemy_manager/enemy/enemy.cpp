#include "enemy.h"

const int CEnemy::m_width = 64;		//幅
const int CEnemy::m_height = 64;	//高さ

//コンストラクタ
CEnemy ::CEnemy (aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Enemy")
{
}

//初期化
void CEnemy ::Initialize(void)
{
	m_Enemy.Create("data\\abe.png");
}

//更新
void CEnemy ::Update(void)
{
}

//描画
void CEnemy ::Draw(void)
{
}

//解放
void CEnemy ::Finalize(void)
{
}
