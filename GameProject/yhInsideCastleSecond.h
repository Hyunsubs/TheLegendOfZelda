#pragma once
#include "yhPlayerTemplate.h"


namespace yh
{

	class InsideCastleSecond : public PlayerTemplate
	{
	public:
		InsideCastleSecond();
		virtual ~InsideCastleSecond();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;

	private:
		Vector2 map_pos;
		Vector2 map_scale;
		Vector2 map_size;

		class MapChanger* to_first_castle;
		class MapChanger* to_first_boss;
	};
}
