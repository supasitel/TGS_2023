#pragma once
#include "aqua.h"

class CBackGround :public aqua::IGameObject
{
public:
	//コンストラクタ
	CBackGround(aqua::IGameObject* parent);

	//デストラクタ
	~CBackGround() = default;

	//初期化
	void Initialize(void);

	//描画
	void Draw(void);

	//解放
	void Finalize(void);
private:
	aqua::CSprite	m_BackGround;	//背景
};