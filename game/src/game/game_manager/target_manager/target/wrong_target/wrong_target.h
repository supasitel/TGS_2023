#pragma once
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/unit.h"

class CWrongTarget :public IUnit
{
public:
	//�R���X�g���N�^
	CWrongTarget(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CWrongTarget() = default;

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

	int		m_WrongTarget_Count;	//�s�����^�[�Q�b�g�̐�
	float   m_Width;				//��
	float	m_Height;				//����
	float   m_Speed;				//���x

	aqua::CSprite	m_WrongTarget;
	aqua::CTimer	m_Timer;
};