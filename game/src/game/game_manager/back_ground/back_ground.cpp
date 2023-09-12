#include "back_ground.h"

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
CBackGround::CBackGround(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "BackGround")
{
}

//‰Šú‰»
void CBackGround::Initialize(void)
{
	//”wŒi
	m_BackGround.Create("data\\main_ground.png");
	//”wŒi‚ÌˆÊ’u
	m_BackGround.position = aqua::CVector2::ZERO;
}

//•`‰æ
void CBackGround::Draw(void)
{
	//”wŒi‚Ì•`‰æ
	m_BackGround.Draw();
}

//‰ğ•ú
void CBackGround::Finalize(void)
{
	//”wŒi‚Ì‰ğ•ú
	m_BackGround.Delete();
}
