#pragma once
#include "aqua.h"

class IUnit :public aqua::IGameObject
{
public:
	IUnit(aqua::IGameObject* parent, const std::string& name, const std::string& category);

	virtual ~IUnit() = default;

	virtual void Initialize(const std::string& file_name);

	virtual void Update(void);

	virtual void Draw(void);

	virtual void Finalize(void);

	aqua::CVector2 GetPosition(void);

	aqua::CVector2 GetCenterPosition(void);

	//ïùéÊìæ
	int GetWidth(void);

	//çÇÇ≥éÊìæ
	int GetHeight(void);

	float GetHitRadius(void);
protected:
	virtual void Move(void);

	//ï«îªíË
	void CheckHitWall(void);

	enum class STATE
	{
		MOVE,
	};

	aqua::CSprite	m_UnitSprite;
	aqua::CVector2	m_Velocity;
	aqua::CVector2	m_Position;
	aqua::CVector2	m_Accelerator;
	int m_Width;
	int m_Height;
	float m_HitRadius;

	STATE	m_State;
};