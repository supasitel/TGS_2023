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
	void Initialize(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;
private:
	aqua::CSprite	m_BackGround;
};