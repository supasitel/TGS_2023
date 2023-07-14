#pragma once
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
private:
	static const int m_min_accelerator;
	static const int m_max_accelerator;
};