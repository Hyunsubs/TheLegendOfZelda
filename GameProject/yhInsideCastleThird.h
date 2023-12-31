#pragma once
#include "yhPlayerTemplate.h"


namespace yh
{

	class InsideCastleThird : public PlayerTemplate
	{
	public:
		InsideCastleThird();
		virtual ~InsideCastleThird();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		Vector2 map_pos;
		Vector2 map_scale;
		Vector2 map_size;


		class MapChanger* to_castle_first;
	};
}
