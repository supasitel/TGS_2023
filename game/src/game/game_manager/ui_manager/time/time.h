#pragma once
#include "aqua.h"
#include "../../scene_manager/scene_manager.h"
#include "../ui_manager.h"

class CTime :public IUIManager
{
public:
	//�R���X�g���N�^
	CTime(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CTime() = default;

	//������
	void Initialize(void);

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	//�I��
	bool Finished(void);

private:
	static const int	m_default_time_limit;	//��������
	static const float  m_one_timer;			//1�b
	int                 m_TimeLimit;			//��������
	aqua::CLabel        m_TimerLabel;			//�^�C�}�[���x��
	aqua::CTimer        m_OneTimer;				//1�b�^�C�}�[
};