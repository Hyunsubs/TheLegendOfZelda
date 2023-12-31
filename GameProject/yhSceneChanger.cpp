#include "yhSceneChanger.h"
#include "yhTransform.h"
#include "yhInput.h"
#include "yhTime.h"
#include "yhScene.h"
#include "yhSceneManager.h"
#include "yhPlay.h"
#include "yhCamera.h"
#include "yhPlayerTemplate.h"

yh::SceneChanger::SceneChanger()
{
}

yh::SceneChanger::~SceneChanger()
{
}

void yh::SceneChanger::Initialize()
{
}

void yh::SceneChanger::Update()
{

	if (Input::GetKey(eKeyCode::Z))
	{
		SceneManager::LoadScene(L"CastleGardenScene");
		Camera::ResetCamera();
	}

	else if (Input::GetKey(eKeyCode::X))
	{
		SceneManager::LoadScene(L"HouseScene");
		Camera::ResetCamera();
	}

	else if (Input::GetKey(eKeyCode::C))
	{
		SceneManager::LoadScene(L"TitleScene");
		Camera::ResetCamera();
	}

	else if (Input::GetKey(eKeyCode::V))
	{
		SceneManager::LoadScene(L"TitleAnimScene");
		Camera::ResetCamera();
	}

	else if (Input::GetKey(eKeyCode::B))
	{
		SceneManager::LoadScene(L"NearHouseScene");
		Camera::ResetCamera();
	}

	else if (Input::GetKey(eKeyCode::N))
	{
		SceneManager::LoadScene(L"InsideCastleFirst");
		Camera::ResetCamera();
	}

}

void yh::SceneChanger::Render(HDC hdc)
{
}
