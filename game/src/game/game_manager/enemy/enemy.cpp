#include "enemy.h"

const int CEnemy::m_width = 64;	//��
const int CEnemy::m_height = 64;	//����

//�R���X�g���N�^
CEnemy::CEnemy(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"Enemy")
{
}

//������
void CEnemy::Initialize(void)
{
	m_Enemy.Create("data\\abe.png");
	m_Enemy.position.x = (float)aqua::GetWindowWidth() / 2.0f - (float)m_Enemy.GetTextureWidth() / 2.0f;
	m_Enemy.position.y = (float)aqua::GetWindowHeight() / 2.0f - (float)m_Enemy.GetTextureHeight() / 2.0f;
}

//�X�V
void CEnemy ::Update(void)
{
}

//�`��
void CEnemy ::Draw(void)
{
	m_Enemy.Draw();
}

//���
void CEnemy ::Finalize(void)
{
	m_Enemy.Delete();
}
