#pragma once
#include "aqua.h"
#include "../../scene.h"

class CClearScene :public IScene
{
public:
	//コンストラクタ
	CClearScene(aqua::IGameObject* parent);

	//デストラクタ
	~CClearScene() = default;

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

	aqua::CLabel	m_Clear;		//クリアメッセージ
	aqua::CLabel	m_Message;		//メッセージ
	aqua::CSprite	m_BackGround;	//背景
	aqua::CSprite	m_Button;		//ボタン
	aqua::CSprite	m_ButtonBlack;	//ボタン(発光)
};
