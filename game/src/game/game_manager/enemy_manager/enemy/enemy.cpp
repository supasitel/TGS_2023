#include "enemy.h"

const int CEnemy::m_width = 64;		//��
const int CEnemy::m_height = 64;	//����

//�R���X�g���N�^
CEnemy ::CEnemy (aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Enemy")
{
}

//������
void CEnemy ::Initialize(void)
{
	m_Enemy.Create("data\\abe.png");
}

//�X�V
void CEnemy ::Update(void)
{
}

//�`��
void CEnemy ::Draw(void)
{
}

//���
void CEnemy ::Finalize(void)
{
}
