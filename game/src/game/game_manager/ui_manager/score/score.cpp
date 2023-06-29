#include "score.h"

const int CScore::m_max_score = 9999;	//�ő�X�R�A
const int CScore::m_min_score = 0;		//�ŏ��X�R�A

//�R���X�g���N�^
CScore::CScore(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Score")
{
}

//������
void CScore::Initialize(void)
{
	//�X�R�A���x��
	m_ScoreLabel.Create(36, 2);
}

//�X�V
void CScore::Update(void)
{
}

//�`��
void CScore::Draw(void)
{
}

//���
void CScore::Finalize(void)
{
	m_ScoreLabel.Delete();
}
