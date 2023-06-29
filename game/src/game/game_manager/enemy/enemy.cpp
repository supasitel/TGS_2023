#include "enemy.h"

const int CEnemy::m_width = 64;		//��
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
	m_Enemy.position = aqua::CVector2::ZERO;
}

//�X�V
void CEnemy ::Update(void)
{
	//aqua::mouse�̏ȗ�
	using namespace aqua::mouse;

	//�}�E�X�̍��W�擾
	aqua::CPoint mpos = GetCursorPos();
	
	//�G�l�~�[��̃}�E�X����
	if (mpos.x<m_Enemy.position.x && mpos.x>m_Enemy.position.x + m_width ||
		mpos.y<m_Enemy.position.y && mpos.y>m_Enemy.position.y + m_height)
	{
	}
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

//���S
void CEnemy::Dead(void)
{
}
