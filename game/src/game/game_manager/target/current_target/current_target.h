#pragma once
#include "aqua.h"

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

	static const int				m_width;
	static const int				m_height;
	static const unsigned int		m_clicked_color;			//クリック時の色
	static const unsigned int		m_default_color;			//選択前の色
	static const unsigned int		m_selected_color;			//選択時の色

	aqua::CSprite					m_CurrentTarget;
};