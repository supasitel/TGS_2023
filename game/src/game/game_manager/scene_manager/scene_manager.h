#pragma once
#include "aqua.h"
#include "../scene_manager/scene/scene_id.h"

class CSceneManager :public aqua::IGameObject
{
public:
	//コンストラクタ
	CSceneManager(aqua::IGameObject* parent);

	//デストラクタ
	~CSceneManager() = default;

	//初期化
	void Initialize(void);

	//更新
	void Update(void);

	//描画
	void Draw(void);

	//解放
	void Finalize(void);

	//シーン変更
	void Change(SCENE_ID id);
	//シーンのスタック
	void Push(SCENE_ID id);

	//シーンの取り出し
	void Eject(void);

	//シーンのリセット
	void Reset(void);

private:
	//状態ID
	enum class STATE
	{
		SCENE_IN,		//シーン開始
		SCENE_UPDATE,	//シーン更新
		SCENE_OUT,		//シーン終了
		SCENE_CHANGE,	//シーン変更
	};

	//シーンの生成
	void Create(SCENE_ID id);

	//現在のシーンの削除
	void Delete(void);

	//シーンの開始
	void SceneIn(void);

	//シーンの更新
	void SceneUpdate(void);

	//シーンの終了
	void SceneOut(void);

	//シーンの変更
	void ScneChange(void);

	SCENE_ID                m_CurrentSceneID;	//現在のシーンID
	SCENE_ID                m_NextSceneID;		//次のシーンID
	SCENE_ID                m_PushSceneID;		//スタックするシーンID
	STATE                   m_State;			//シーン状態
	bool					m_PushFlag;			//スタックフラグ
	static const float      m_fade_speed;		//フェード速度
	aqua::CBoxPrimitive     m_FadePlane;		//フェードプレーン

};