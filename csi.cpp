#include "csi.hpp"

std::string csi::enable(style style){
	return prefix + std::to_string(
		(int)style + (int)style::enable_offset
	) + "m";
}

std::string csi::disable(style style){
	return prefix + std::to_string(
		(int)style + (int)style::disable_offset
	) + "m";
}

std::string csi::foreground(color color){
	return prefix + std::to_string(
		(int)color + (int)color::foreground_offset
	) + "m";
}

std::string csi::background(color color){
	return prefix + std::to_string(
		(int)color + (int)color::background_offset
	) + "m";
}

std::string csi::cursor_up(int cells){
	return {
		prefix +
		std::to_string(cells) +	"A"
	};
}

std::string csi::cursor_down(int cells){
	return {
		prefix +
		std::to_string(cells) +	"B"
	};
}

std::string csi::cursor_forward(int cells){
	return {
		prefix +
		std::to_string(cells) +	"C"
	};
}

std::string csi::cursor_back(int cells){
	return {
		prefix +
		std::to_string(cells) +	"D"
	};
}

std::string csi::cursor_next_line(int lines){
	return {
		prefix +
		std::to_string(lines) +	"E"
	};
}

std::string csi::cursor_previous_line(int lines){
	return {
		prefix +
		std::to_string(lines) +	"F"
	};
}

std::string csi::cursor_position(int row, int column){
	return {
		prefix +
		std::to_string(row) + ";" +
		std::to_string(column) + "H"
	};
}

std::string csi::erase_display(erase_mode mode){
	return {
		prefix +
		std::to_string((int)mode) + "J"
	};
}

std::string csi::erase_line(erase_mode mode){
	return {
		prefix +
		std::to_string((int)mode) + "K"
	};
}

std::string csi::scroll_up(int lines){
	return {
		prefix +
		std::to_string(lines) + "S"
	};
}

std::string csi::scroll_down(int lines){
	return {
		prefix +
		std::to_string(lines) + "T"
	};
}

std::string csi::select_graphic_rendition(int code){
	return {
		prefix +
		std::to_string(code) + "m"
	};
}
