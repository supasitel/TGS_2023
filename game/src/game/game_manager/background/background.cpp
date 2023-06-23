#include "background.h"

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
CBackGround::CBackGround(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"BackGround")
{
}

//‰Šú‰»
void CBackGround::Initialize(void)
{
	//”wŒi¶¬
	m_BackGround.Create("data\\magic_circle.png");
	//”wŒi‚ÌˆÊ’u
	m_BackGround.position = aqua::CVector2::ZERO;
}

//•`‰æ
void CBackGround::Draw(void)
{
	m_BackGround.Draw();
}

//‰ğ•ú
void CBackGround::Finalize(void)
{
	m_BackGround.Delete();
}
