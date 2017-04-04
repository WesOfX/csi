#pragma once
#include <string>

namespace csi{
	enum class style{
		bold = 1,
		italics = 3,
		underlined = 4,
		strikethrough = 9,
		inverse = 7,
		enable_offset = 0,  // e.g. enable bold is 1
		disable_offset = 20 // and dilable bold is 21
	};	
	
	enum class color{
		none = 9,
		black = 0,
		red = 1,
		green = 2,
		yellow = 3,
		blue = 4,
		magenta = 5,
		cyan = 6,
		white = 7,
		foreground_offset = 30, // e.g. green foreground is 32.
		background_offset = 40  // and green background is 42.
	};	
	
	enum class erase_mode{
		to_end = 0,
		to_beginning = 1,
		all = 2
	};

	const std::string prefix = "\033[";
	const std::string save_cursor_position = prefix + "s";
	const std::string restore_cursor_position = prefix + "u";

	std::string enable(style style);
	std::string disable(style style);
	std::string foreground(color color = color::none);
	std::string background(color color = color::none);
	std::string cursor_up(int rows = 1);
	std::string cursor_down(int rows = 1);
	std::string cursor_forward(int columns = 1);
	std::string cursor_back(int columns = 1);
	std::string cursor_next_line(int lines = 1);
	std::string cursor_previous_line(int lines = 1);
	std::string cursor_position(int row = 1, int column = 1);
	std::string erase_display(erase_mode mode = erase_mode::all);
	std::string erase_line(erase_mode mode = erase_mode::all);
	std::string scroll_up(int lines = 1);
	std::string scroll_down(int lines = 1);
	std::string select_graphic_rendition(int code = 0);
};
