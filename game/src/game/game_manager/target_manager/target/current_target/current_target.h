#pragma once
#include "../../../unit/unit.h"
#include "../../../scene_manager/scene_manager.h"

class CCurrentTarget :public IUnit
{
public:
	//�R���X�g���N�^
	CCurrentTarget(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CCurrentTarget() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

private:
	static const std::string	m_name;		//���O
	static const std::string	m_category;	//�J�e�S���[
	static const float m_one_timer;			//�P�b
	static const float m_max_speed;			//�ō����x
	static const float m_min_speed;			//�Œᑬ�x
	static const int   m_width;
	static const int   m_height;

	int		m_CurrentTarget_Count;	//�����^�[�Q�b�g�̐�
	float   m_Width;				//��
	float	m_Height;				//����
	float   m_Speed;				//���x

	aqua::CSprite	m_CurrentTarget;	//�����^�[�Q�b�g�X�N���v�g
	aqua::CTimer	m_Timer;			//�^�C�}�[�X�N���v�g
};