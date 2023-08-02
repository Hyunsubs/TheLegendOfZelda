#pragma once
#include "yhGameObject.h"


namespace yh
{
	class HpInterface : public GameObject
	{
	public:
		HpInterface();
		virtual ~HpInterface();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other) override;
		virtual void OnCollisionStay(class Collider* other) override;
		virtual void OnCollisionExit(class Collider* other) override;


	private:
		class SpriteRenderer* sr;
		class Texture* image;
		class Transform* tr;

	};
}


