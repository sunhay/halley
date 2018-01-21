#pragma once

#include "../ui_widget.h"
#include "halley/core/graphics/sprite/sprite.h"
#include "halley/core/graphics/text/text_renderer.h"
#include "ui_clickable.h"

namespace Halley {
	class UIStyle;
	class UIValidator;
	class UIList;
	class UIScrollPane;

	class UIDropdown : public UIClickable {
	public:
		explicit UIDropdown(String id, UIStyle style, UIStyle scrollbarStyle, UIStyle listStyle, const std::vector<String>& options, int defaultOption = 0);

		void setSelectedOption(int option);
		void setSelectedOption(const String& option);
		int getSelectedOption() const;
		String getSelectedOptionText() const;

		void setInputButtons(const UIInputButtons& buttons) override;

	protected:
		void draw(UIPainter& painter) const override;
		void drawChildren(UIPainter& painter) const override;
		void update(Time t, bool moved) override;

		void onClicked(Vector2f mousePos) override;
		void doSetState(State state) override;

		bool isFocusLocked() const override;

	private:
		Sprite sprite;
		TextRenderer label;
		UIInputButtons inputButtons;
		UIStyle style;
		UIStyle scrollbarStyle;
		UIStyle listStyle;
		std::shared_ptr<UIWidget> dropdownWindow;
		std::shared_ptr<UIList> dropdownList;
		std::shared_ptr<UIScrollPane> scrollPane;
		
		std::vector<String> options;
		int curOption = 0;
		bool isOpen = false;

		void open();
		void close();
    };
}