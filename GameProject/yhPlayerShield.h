#pragma once
#include "yhGameObject.h"

namespace yh
{
	class PlayerShield : public GameObject
	{
	public:
		enum class ShieldState
		{
			Idle,
			Move,
			Attack,
			Death,
			Map,
			Falling,
			Ui,
			End,
		};



		PlayerShield();
		virtual ~PlayerShield();


		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;


		void Idle();
		void Move();
		void Attack();
		void Death();
		void Map();
		void Falling();
		void Ui();

		void SetDirection(Directions direct) { direction = direct; }

	private:
		ShieldState state;
		Directions direction;
		class Transform* tr;
		class SpriteRenderer* sr;
		class Texture* image;
		class Animator* anim;
	};
}
