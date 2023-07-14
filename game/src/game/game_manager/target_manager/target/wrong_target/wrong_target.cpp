#include "wrong_target.h"

const int CWrongTarget::m_max_accelerator = 400;
const int CWrongTarget::m_min_accelerator = 300;

//コンストラクタ
CWrongTarget::CWrongTarget(aqua::IGameObject* parent)
	:ITarget(parent, "WrongTarget")
{
}

//初期化
void CWrongTarget::Initialize(void)
{
	ITarget::Initialize("data\\wrong.png");

	m_Position.x = (float)aqua::GetWindowWidth() - m_Width;
	m_Position.y = (float)aqua::GetWindowHeight() - m_Height;

	m_Accelerator = aqua::CVector2((float)aqua::Rand(m_max_accelerator, m_min_accelerator) * -1.0f, 0.0f);
}
