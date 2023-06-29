#pragma once
#include "aqua.h"

class CTime :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CTime(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CTime() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	aqua::CTimer	m_Time;
};