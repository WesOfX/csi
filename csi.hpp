#pragma once

#include <string>

namespace csi{
	// Control sequence introducer string which prefixes every control sequence.
	const std::string prefix = "\033[";

	// Enum for style codes.
	enum class style_code{
		bold = 1,
		italics = 3,
		underlined = 4,
		strikethrough = 9,
		inverse = 7,
		enable_offset = 0, // e.g. enable bold is 1 and enable italics is 3.
		disable_offset = 20 // e.g. disable bold is 21 and disable italics is 23.
	};

	// Return a control sequence string which enables a text style.
	std::string enable(style_code style);

	// Return a control sequence string which disables a text style.
	std::string disable(style_code style);

	// Return a control sequence string which enables or disables text styles.
	std::string style(
		bool bold = false,
		bool italics = false,
		bool underlined = false,
		bool strikethrough = false
	);

	// Enum for color codes.
	enum class color_code{
		none = 9, // The terminal's default colors.
		black = 0,
		red = 1,
		green = 2,
		yellow = 3,
		blue = 4,
		magenta = 5,
		cyan = 6,
		white = 7,
		foreground_offset = 30, // e.g. green foreground is 32.
		background_offset = 40 // e.g. green background is 42.
	};

	// Return a control sequence string which sets the text color.
	std::string foreground(color_code color = color_code::none);

	// Return a control sequence string which sets the text background color.
	std::string background(color_code color = color_code::none);

	/* Return a control sequence string which selects foreground and background
	 * text colors.
	 * Additionally, the colors can be inverted to make the text appear
	 * highlighted. */
	std::string color(
		color_code foreground = color_code::none,
		color_code background = color_code::none,
		bool inverse = false
	);

	// Return a control sequence string which moves the cursor up.
	std::string cursor_up(int rows = 1);

	// Return a control sequence string which moves the cursor down.
	std::string cursor_down(int rows = 1);

	// Return a control sequence string which moves the cursor forward.
	std::string cursor_forward(int columns = 1);

	// Return a control sequence string which moves the cursor back.
	std::string cursor_back(int columns = 1);

	/* Return a control sequence string which moves the cursor to.
	 * the first column of the next line */
	std::string cursor_next_line(int lines = 1);

	/* Return a control sequence string which moves the cursor to.
	 * the first column of the previous line */
	std::string cursor_previous_line(int lines = 1);

	// Return a control sequence string which moves the cursor anywhere.
	std::string cursor_position(int row = 1, int column = 1);

	// Enum for all the erase modes.
	enum class erase_mode{
		to_end = 0, // Erase from the cursor to end of the line/display.
		to_beginning = 1, // Erase from the cursor to beginning of the line/display.
		all = 2 // Erase the entire line/display.
	};

	// Return a control sequence string which erases the display.
	std::string erase_display(erase_mode mode = erase_mode::all);

	// Return a control sequence string which erases the current line.
	std::string erase_line(erase_mode mode = erase_mode::all);

	// Return a control sequence string which scrolls the display up.
	std::string scroll_up(int lines = 1);

	// Return a control sequence string which scrolls the display down.
	std::string scroll_down(int lines = 1);

	/* Return a control sequence string which selects a graphics setting.
	 * Check online for SGR codes. */
	std::string select_graphic_rendition(int code = 0);

	// Control sequence string which saves the cursor position.
	const std::string save_cursor_position = prefix + "s";

	// Control sequence string which restores the cursor position.
	const std::string restore_cursor_position = prefix + "u";
};
