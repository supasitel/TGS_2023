#pragma once
#include "../../../unit/unit.h"
#include "aqua.h"

class CWrong3 :public IUnit
{
public:
	//�R���X�g���N�^
	CWrong3(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CWrong3() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	void CheckHitMouse(void);
private:
	static const int m_width;
	static const int m_height;
	static const float m_one_timer;			//�P�b
	static const float m_max_speed;			//�ō����x
	static const float m_min_speed;			//�Œᑬ�x
	static const std::string	m_name;		//���O
	static const std::string	m_category;	//�J�e�S���[

	float   m_Width;				//��
	float	m_Height;				//����
	float   m_Speed;				//���x

	aqua::CSprite	m_Wrong3;
	aqua::CTimer	m_Timer;
};