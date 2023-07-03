#pragma once
#include "aqua.h"
#include "../ui_manager.h"

class CTime :public IUIManager
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

	//�I��
	bool Finished(void);
private:
	static const float m_one_timer;		//�P�b
	static const int   m_time_limit;	//��������	
	aqua::CTimer	   m_Timer;			//�P�b�^�C�}�[
	aqua::CLabel	   m_TimerLabel;	//�^�C�}�[���x��
	int				   m_TimeLimit;		//��������
};