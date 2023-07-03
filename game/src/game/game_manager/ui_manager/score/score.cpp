#include "score.h"

const int CScore::m_max_score = 9999;	//�ő�X�R�A
const int CScore::m_min_score = 0;		//�ŏ��X�R�A

//�R���X�g���N�^
CScore::CScore(aqua::IGameObject* parent)
	:IUIManager(parent, "Score")
	,m_Score(0)
{
}

//������
void CScore::Initialize(void)
{
	//�X�R�A���x������
	m_ScoreLabel.Create(36, 2);

	IUIManager::Initialize();
}

//�X�V
void CScore::Update(void)
{
	//�X�R�A���x���e�L�X�g
	m_ScoreLabel.text = "�X�R�A" + std::to_string(m_Score);

	//�X�R�A���x���ʒu
	m_ScoreLabel.position = { 500.0f,0.0f };
}

//�`��
void CScore::Draw(void)
{
	m_ScoreLabel.Draw();
}

//���
void CScore::Finalize(void)
{
	m_ScoreLabel.Delete();
}

//�X�R�A�̉��Z
void CScore::Add(int score)
{
	m_Score += score;

	//�X�R�A�̏㉺���`�F�b�N
	if (m_Score < m_min_score)
		m_Score = m_min_score;
	else if (m_Score > m_max_score)
		m_Score = m_max_score;
}

//�X�R�A�̃N���A
void CScore::Clear(void)
{
	//�X�R�A��0�ɂ���
	m_Score = 0;
}

//�X�R�A�̎擾
int CScore::GetScore(void) const
{
	//�X�R�A��Ԃ�
	return m_Score;
}
