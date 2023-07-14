#pragma once
#include "aqua.h"
#include "../target.h"

class CWrongTarget :public ITarget
{
public:
	//コンストラクタ
	CWrongTarget(aqua::IGameObject* parent);

	//デストラクタ
	~CWrongTarget() = default;

	//初期化
	void Initialize(void)override;

	//更新
	void Update(void)override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;
private:
	//色
	void SetColor(const aqua::CColor&& color);

	static const unsigned int		m_clicked_color;			//クリック時の色
	static const unsigned int		m_default_color;			//選択前の色
	static const int				m_height;					//幅
	static const int 				m_width;					//高さ
	static const float				m_radius;					//
	static const float				m_max_velocity;				//
	static const float				m_min_velocity;				//

	aqua::CSprite					m_WrongTarget;				//ターゲット(間違い)
};