#pragma once
#include "aqua.h"

enum class SOUND_ID
{
	BGM,		//BGM
	DECISION,	//決定音
	CLICK,		//クリック音
	CORRENT,	//正解音
	MISTAKE,	//間違い音

	MAX			//サウンドIDの数
};

class CSoundManager :public aqua::IGameObject
{
public:
	//コンストラクタ
	CSoundManager(aqua::IGameObject* parent);

	//デストラクタ
	~CSoundManager() = default;

	//初期化
	void Initialize(void)override;

	//解放
	void Finalize(void)override;

	//再生
	void Play(SOUND_ID id);
private:
	static const std::string m_sound_file_name[];
	aqua::CSoundPlayer* m_SoundPlayer;
};