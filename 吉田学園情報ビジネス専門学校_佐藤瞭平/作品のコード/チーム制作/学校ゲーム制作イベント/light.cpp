//=============================================================================
//
// ライトの処理[light.cpp]
// Author : 佐藤瞭平
//
//=============================================================================
#include"light.h"
#include"manager.h"
#include"renderer.h"

//=============================================================================
// 静的メンバ変数の宣言
//=============================================================================
int CLight::m_nCntLight = 0;

//=============================================================================
// ライトのコンストラクタ
//=============================================================================
CLight::CLight()
{
	m_nNumLight = m_nCntLight;
	m_nCntLight++;
}


//=============================================================================
// ライトのデストラクタ
//=============================================================================
CLight::~CLight()
{
	m_nCntLight--;
}

//=============================================================================
// ライトの初期化処理
//=============================================================================
HRESULT CLight::Init(D3DXVECTOR3 vec, D3DXCOLOR col)
{
	D3DXVECTOR3 vecDir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//設定用方向ベクトル

	//デバイスへのポインタ
	LPDIRECT3DDEVICE9 pDevice = NULL;	

	//デバイスの取得
	pDevice = CManager::GetRenderer()->GetDevice();

	//ライトをクリアする
	ZeroMemory(&m_light, sizeof(D3DLIGHT9));	//値を0にする

	//ライトの種類を設定
	m_light.Type = D3DLIGHT_DIRECTIONAL;	//平方ほうげん

	//ライトの拡散光を設定
	m_light.Diffuse = col;

	//ライトの方向を設定
	D3DXVec3Normalize(&vecDir, &vec);	//正規化する

	m_light.Direction = vecDir;

	//ライトを設定する
	pDevice->SetLight(m_nNumLight, &m_light);

	//ライトを有効にする
	pDevice->LightEnable(m_nNumLight, TRUE);
	return S_OK;
}

//=============================================================================
// ライトの終了処理
//=============================================================================
void CLight::Uninit(void)
{

}

//=============================================================================
// ライトの更新処理
//=============================================================================
void CLight::Update(void)
{

}