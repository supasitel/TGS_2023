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
	static const int m_width;		//幅
	static const int m_height;		//高さ

	aqua::CLabel	m_Over;			//ゲームオーバーラベル
	aqua::CLabel	m_Message;		//メッセージラベル
	aqua::CSprite	m_Button;		//ボタンスプライト
	aqua::CSprite	m_ButtonBlack;	//ボタン（発光）スプライト
	aqua::CSprite	m_BackGround;	//背景
};