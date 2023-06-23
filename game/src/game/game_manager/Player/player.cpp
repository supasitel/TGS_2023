#include "player.h"

const int CPlayer::m_width = 64;	//幅
const int CPlayer::m_height = 64;	//高さ

//コンストラクタ
CPlayer::CPlayer(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Player")
{
}

//初期化
void CPlayer::Initialize(void)
{
}

//更新
void CPlayer::Update(void)
{
}

//描画
void CPlayer::Draw(void)
{
}

//解放
void CPlayer::Finalize(void)
{
}
