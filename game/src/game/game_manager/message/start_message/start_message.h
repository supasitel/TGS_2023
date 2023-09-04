#pragma once
#include "aqua.h"

class CStartMessage :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CStartMessage(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CStartMessage() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;
private:
	aqua::CSprite	m_StartMessage;		//�X�^�[�g���b�Z�[�W
	static const float m_min_scale;		//�ŏ��g�嗦
	static const float m_max_scale;		//�ő�g�嗦
	static const float m_easing_time;	//�C�[�W���O����
	static const float m_view_time;		//���b�Z�[�W�\������
	float	m_ElapsedTime;				//�o�ߎ���
};