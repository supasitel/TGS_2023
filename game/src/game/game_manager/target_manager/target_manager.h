#pragma once
#include "aqua.h"
#include "target/target_id.h"

class CTargetManager :public aqua::IGameObject
{
public:
	CTargetManager(aqua::IGameObject* parent);

	~CTargetManager() = default;

	void Initialize(void)override;

	void Update(void)override;

	void Create(TARGET_ID id);
private:
};