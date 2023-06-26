#pragma once
#include "aqua.h"
#include "../scene.h"

class CTitleScene :public IScene
{
public:
	//コンストラクタ
	CTitleScene(aqua::IGameObject* parent);

	//デストラクタ
	~CTitleScene() = default;

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

	aqua::CSprite	m_Title;
	aqua::CSprite	m_BackGround;
};
