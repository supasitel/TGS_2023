#include "enemy.h"

const int CEnemy::m_width = 64;		//幅
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
	m_Enemy.position = aqua::CVector2::ZERO;
}

//更新
void CEnemy ::Update(void)
{
	//aqua::mouseの省略
	using namespace aqua::mouse;

	//マウスの座標取得
	aqua::CPoint mpos = GetCursorPos();
	
	//エネミー上のマウス判定
	if (mpos.x<m_Enemy.position.x && mpos.x>m_Enemy.position.x + m_width ||
		mpos.y<m_Enemy.position.y && mpos.y>m_Enemy.position.y + m_height)
	{
	}
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

//死亡
void CEnemy::Dead(void)
{
}
