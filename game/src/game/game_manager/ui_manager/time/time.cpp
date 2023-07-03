#include "time.h"

const float CTime::m_one_timer = 1.0;	//�P�b
const int   CTime::m_time_limit = 60;	//��������

//�R���X�g���N�^
CTime::CTime(aqua::IGameObject* parent)
	:IUIManager(parent,"Time")
{
}

//������
void CTime::Initialize(void)
{
	//�^�C�}�[���x������
	m_TimerLabel.Create(36, 2);

	//�^�C�}�[�ݒ�
	m_Timer.Setup(m_one_timer);

	//�������ԑ��
	m_TimeLimit = m_time_limit;

	IUIManager::Initialize();
}

//�X�V
void CTime::Update(void)
{
	//�I��������Ԃ�
	if (Finished())
		return;

	//�P�b�^�C�}�[�̍X�V
	m_Timer.Update();

	//�P�b�^�C�}�[���I��������
	if (m_Timer.Finished())
	{
		//�P�b�^�C�}�[�����Z�b�g
		m_Timer.Reset();

		//�������Ԃ��P�����炷
		--m_TimeLimit;
	}
}

//�`��
void CTime::Draw(void)
{
	//�^�C�}�[���x���e�L�X�g
	m_TimerLabel.text = "�c��" + std::to_string(m_TimeLimit) + "�b";
	
	//�^�C�}�[���x���ʒu
	m_TimerLabel.position = { 800.0f,0.0f };

	m_TimerLabel.Draw();
}

//���
void CTime::Finalize(void)
{
	m_TimerLabel.Delete();
}

//�I��
bool CTime::Finished(void)
{
	//�������Ԃ��O�b�ȉ��ɂȂ�����Ԃ�
	return (m_TimeLimit <= 0);
}
