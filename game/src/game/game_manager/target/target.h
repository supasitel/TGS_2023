#pragma once
#include "aqua.h"

class CTarget :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CTarget(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CTarget() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	static const int m_width;
	static const int m_height;

	aqua::CSprite	m_Target;
};