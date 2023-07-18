#pragma once
#include "aqua.h"
#include "unit/unit.h"
#include "unit/unit_id.h"

class CUnitManager :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CUnitManager(aqua::IGameObject* parent, const std::string& name);

	//�f�X�g���N�^
	~CUnitManager() = default;

	//���j�b�g�̐���
	void Create(UNIT_ID id);
private:
};