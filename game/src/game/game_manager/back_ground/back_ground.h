#pragma once
#include "aqua.h"

class CBackGround :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CBackGround(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CBackGround() = default;

	//������
	void Initialize(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	aqua::CSprite	m_BackGround;
};