#include "background.h"

//�R���X�g���N�^
CBackGround::CBackGround(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BackGround")
{
}

//������
void CBackGround::Initialize(void)
{
	//�w�i����
	m_BackGround.Create("data\\magic_circle.png");
	//�w�i�̈ʒu
	m_BackGround.position = aqua::CVector2::ZERO;
}

//�`��
void CBackGround::Draw(void)
{
	m_BackGround.Draw();
}

//���
void CBackGround::Finalize(void)
{
	m_BackGround.Delete();
}
