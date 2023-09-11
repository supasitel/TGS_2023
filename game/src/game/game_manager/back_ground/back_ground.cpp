#include "back_ground.h"

//�R���X�g���N�^
CBackGround::CBackGround(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "BackGround")
{
}

//������
void CBackGround::Initialize(void)
{
	//�w�i
	m_BackGround.Create("data\\main_ground.png");
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
