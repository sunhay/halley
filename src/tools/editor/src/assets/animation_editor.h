#pragma once

#include "halley/core/graphics/sprite/animation.h"
#include "halley/core/resources/resources.h"
#include "halley/ui/ui_factory.h"
#include "halley/ui/ui_widget.h"

namespace Halley {
	class Project;

	class AnimationEditor : public UIWidget {
    public:
        AnimationEditor(UIFactory& factory, Resources& resources, Project& project, const String& assetId, AssetType type);

	private:
		UIFactory& factory;
		Project& project;
		std::shared_ptr<const Resource> resource;

		void setupWindow();
	};

	class AnimationEditorDisplay : public UIWidget {
	public:
		AnimationEditorDisplay(String id, Resources& resources);

		void setZoom(float zoom);
		void setAnimation(std::shared_ptr<const Animation> animation);
		void setSprite(std::shared_ptr<const SpriteResource> sprite);
		void setTexture(std::shared_ptr<const Texture> texture);
		void setSequence(const String& sequence);
		void setDirection(const String& direction);

	protected:
		void update(Time t, bool moved) override;
		void draw(UIPainter& painter) const override;

	private:
		Resources& resources;
		std::shared_ptr<const Animation> animation;
		AnimationPlayer animationPlayer;

		Sprite origSprite;
		Sprite drawSprite;
		Sprite boundsSprite;
		Sprite nineSliceVSprite;
		Sprite nineSliceHSprite;
		Sprite pivotSprite;
		Rect4f bounds;
		float zoom = 1.0f;

		void updateBounds();
	};
}

