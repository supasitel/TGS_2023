#pragma once
#include "../target.h"

class CWrongTarget :public ITarget
{
public:
	//�R���X�g���N�^
	CWrongTarget(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CWrongTarget() = default;

	//������
	void Initialize(void)override;
private:
	static const int m_min_accelerator;
	static const int m_max_accelerator;
};