#pragma once
#include "aqua.h"
#include "../../scene.h"

class COver :public IScene
{
public:
	//コンストラクタ
	COver(aqua::IGameObject* parent);

	//デストラクタ
	~COver() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

private:
	static const int m_width;
	static const int m_height;

	aqua::CLabel	m_Over;
	aqua::CLabel	m_Message;
	aqua::CSprite	m_Button;
	aqua::CSprite	m_ButtonBlack;
};