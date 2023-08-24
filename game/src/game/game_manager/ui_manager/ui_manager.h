#include "aqua.h"

class IUIManager :public aqua::IGameObject
{
public:
	//コンストラクタ
	IUIManager(aqua::IGameObject* parent, const std::string& name);

	//デストラクタ
	~IUIManager() = default;

	//初期化
	void Initialize(void)override;
private:
	static const std::string	m_ui_category;	//カテゴリー
};