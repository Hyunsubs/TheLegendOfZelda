#include "yhMapChanger.h"
#include "yhTransform.h"
#include "yhSceneManager.h"
#include "yhCollider.h"
#include "yhPlayer.h"
#include "yhSound.h"
#include "yhResources.h"

namespace yh
{
	MapChanger::MapChanger() :
		  col(nullptr)
		, tr(nullptr)
		, scene_name(L"")
		, load_pos(Vector2::Zero)
		, play_sound(false)
	{
		col = AddComponent<Collider>();
		tr = GetComponent<Transform>();

		wstring sound_path = SOUND_PATH;
		puzzle_sound = Resources::Load<Sound>(L"PuzzleSolved",sound_path + L"puzzle_solved.wav");
	}

	MapChanger::~MapChanger()
	{
	}

	void MapChanger::Initialize()
	{
	}

	void MapChanger::Update()
	{
		GameObject::Update();
	}

	void MapChanger::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void MapChanger::OnCollisionEnter(Collider* other)
	{
		Player* cur_player = dynamic_cast<Player*>(other->GetOwner());
		Directions direct = cur_player->GetDirection();
		if (play_sound)
		{
			puzzle_sound->Play(false);
		}

		std::ofstream ofs("..\\Resources\\SaveData\\PlayerDirection.txt", std::ios::out | std::ios::trunc);
		if (ofs.fail())
		{
			std::cout << "Error!" << std::endl;
		}
		ofs << (int)direct;

		ofs.close();
		if (scene_name == L"")
		{
			return;
		}
		SaveLoadPos(load_pos);
		SceneManager::LoadScene(scene_name);
	}
	void MapChanger::OnCollisionStay(Collider* other)
	{
	}
	void MapChanger::OnCollisionExit(Collider* other)
	{
	}
	void MapChanger::SetColliderSize(Vector2 size)
	{
		col->SetSize(size);
	}
	void MapChanger::SetSceneName(std::wstring name)
	{
		scene_name = name;
	}
	void MapChanger::SaveLoadPos(Vector2 pos)
	{
		std::ofstream ofs("..\\Resources\\SaveData\\PlayerPosition.txt", std::ios::out | std::ios::trunc);
		if (ofs.fail())
		{
			std::cout << "Error!" << std::endl;
		}
		ofs << pos.x;
		ofs << "\n";
		ofs << pos.y;
		ofs << "\n";

		ofs.close();
	}
}