#pragma once
#include "aqua.h"
#include "../scene.h"

class CExplanationScene :public IScene
{
public:
	//コンストラクタ
	CExplanationScene(aqua::IGameObject* parent);

	//デストラクタ
	~CExplanationScene() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;
private:
	aqua::CSprite	m_BackGround;	//背景
	aqua::CSprite	m_Target;		//ターゲット
	aqua::CLabel	m_Explanation;	//説明
	aqua::CLabel	m_Label;		//ラベル
};