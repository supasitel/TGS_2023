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
	static const int m_width;
	static const int m_height;

	aqua::CLabel	m_Clear;
	aqua::CLabel	m_Message;
	aqua::CSprite	m_BackGround;
	aqua::CSprite	m_Button;
	aqua::CSprite	m_ButtonBlack;
};
