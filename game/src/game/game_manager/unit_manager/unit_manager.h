#pragma once
#include "aqua.h"
#include "unit/unit.h"

class CUnitManager :public aqua::IGameObject
{
public:
	//���j�b�gID
	enum class UNIT_ID
	{
		CURRENT,
		WRONG,

		MAX
	};

	//�R���X�g���N�^
	CUnitManager(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CUnitManager() = default;

	//���j�b�g�̐���
	void Create(UNIT_ID id);
private:
};