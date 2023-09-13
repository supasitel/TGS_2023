#pragma once
#include "../../../unit/unit.h"
#include "aqua.h"

class CWrong3 :public IUnit
{
public:
	//�R���X�g���N�^
	CWrong3(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CWrong3() = default;

	//������
	void Initialize(void)override;

	//�X�V
	void Update(void)override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	void CheckHitMouse(void);
private:
};