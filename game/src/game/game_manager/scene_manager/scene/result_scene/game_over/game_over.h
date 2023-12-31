#pragma once
#include "aqua.h"
#include "../../scene.h"

class CGameOver :public IScene
{
public:
	//コンストラクタ
	CGameOver(aqua::IGameObject* parent);

	//デストラクタ
	~CGameOver() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;
private:
	static const int m_width;		//2種類のボタンの幅
	static const int m_height;		//2種類のボタンの高さ

	aqua::CLabel	m_GameOver;			//ゲームオーバーラベル
	aqua::CLabel	m_Message;		//メッセージラベル
	aqua::CSprite	m_Button;		//ボタンスプライト
	aqua::CSprite	m_ButtonBlack;	//ボタン（発光）スプライト
	aqua::CSprite	m_BackGround;	//背景スプライト
};