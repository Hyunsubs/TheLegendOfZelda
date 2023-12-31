#pragma once
#include "yhGameObject.h"

namespace yh
{
	enum class grass_state
	{
		Idle,
		Flying,
		Destroyed,
		Death
	};

	class Grass : public GameObject
	{
	public:
		Grass();
		virtual ~Grass() override;



		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;

		grass_state GetGrassState() { return state; }
		void SetGrassState(grass_state input) { state = input; }

		void SetDirection(Directions input) { direct = input; }
		void GrassMoving(Directions direct);
		void DestroyAnim();
		void Death();

	private:
		std::wstring name;
		std::wstring path;

		float flying_time;
		Directions direct;
		bool is_destyoed;

		grass_state state;


		class Transform* tr;
		class Texture* image;
		class Collider* col;
		class SpriteRenderer* sr;
		class Animator* anim;
		class Sound* destroy_sound;
		class Sound* grab_sound;
		
		bool grab_sound_played;
		bool destroy_sound_played;

	};
}


