#pragma once
#include "aqua.h"
#include "../../scene_manager/scene/scene.h"

class CCurrentTarget :public aqua::IGameObject
{
public:
	//コンストラクタ
	CCurrentTarget(aqua::IGameObject* parent);

	//デストラクタ
	~CCurrentTarget() = default;

	//初期化
	void Initialize(void);

	//更新
	void Update(void);

	//描画
	void Draw(void);

	//解放
	void Finalize(void);
private:
	//色
	void SetColor(const aqua::CColor&& color);

	static const int				m_width;					//幅
	static const int				m_height;					//高さ
	static const unsigned int		m_clicked_color;			//クリック時の色
	static const unsigned int		m_default_color;			//選択前の色

	aqua::CSprite					m_CurrentTarget;
};