#pragma once
#include "aqua.h"

class CPlayer :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CPlayer(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CPlayer() = default;

	//������
	void Initialize(void);

	//�X�V
	void Update(void);

	//�`��
	void Draw(void);

	//���
	void Finalize(void);
private:
	static const int m_width;	//��
	static const int m_height;	//����

	aqua::CSprite	m_Player;	//�v���C���[
};
