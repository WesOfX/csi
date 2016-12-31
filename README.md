![Demo screenshot!](https://i.sli.mg/tpP4nf.png)

## Why is this library useful?
`csi` provides easy to use methods that return special strings for controlling the terminal. For example, `enable(style_code::bold)` and `disable(style_code::bold)` return `"\033[1m"` and `"\033[21m"` which the terminal interprets as commands to enable and disable bold.

## How to print text with style:
The `enable` and `disable` methods take `style_code` values and return strings that enable or disable a style. `style_code` is an `enum class` of 5 styles: `bold`, `italics`, `underline`, `strikethrough`, and `inverse`. `inverse` inverts the text color and the background color as-if the text is highlighted.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Enable bold, print "Hello World!",
	   disable bold, then print a newline. */
	std::cout << csi::enable(csi::style_code::bold)
	          << "Hello World!"
	          << csi::disable(csi::style_code::bold)
	          << std::endl;
}
```
The `style` method returns strings that can enable and disable all styles simultaneously. The method accepts 5 optional `bool`, all `false` by default.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	// Enable italics and strikethrough
	std::cout << csi::style(
		false, // Bold
		true,  // Italics
		false, // Underlined
		true,  // Strikethrough
		false  // Inverse
	);

	/* Print "Hello World!", disable all
	   styles, then print a new line. */
	std::cout << "Hello World!"
	          << csi::style()
	          << std::endl;
}
```
## How to print text with color:
The `foreground` and `background` methods take `color_code` values and return strings that set the text color or the background color. `color_code` is an `enum class` of 9 colors: `none`, `black`, `red`, `green`, `yellow`, `blue`, `magenta`, `cyan`, and `white`. `none` is the terminal's default color.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the text color to yellow, print "Hello World!",
	   set the text color to default, then print a new line */
	std::cout << csi::foreground(csi::color_code::yellow)
	          << "Hello World!"
	          << csi::foreground()
	          << std::endl;
		  
	/* Set the background color to blue, print "Hello World!", 
	 * set the background color to default, then print a new line */
	std::cout << csi::background(csi::color_code::blue)
	          << "Hello World!"
	          << csi::background()
	          << std::endl;
}
```
The `color` method returns strings that set the text color and the background color simultaneously. The method accepts 2 optional `color_code`, both of which are `none` by default.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the text color to cyan and
	   the background color to magenta. */
	std::cout << csi::color(
		csi::color_code::cyan,    // Foreground (Text) color
		csi::color_code::magenta, // Background color
	);

	/* Print "Hello World!", set
	 * the colors to default, then
	 * print a new line. */
	std::cout << "Hello World!"
	          << csi::color()
	          << std::endl;
}
```
## How to move the cursor:
There are 7 methods for moving the cursor: `cursor_up`, `cursor_down`, `cursor_forward`, `cursor_back`, `cursor_next_line`, `cursor_previous_line`, and `cursor_position`. `cursor_position` accepts two parameters: `row` and `column`, both 1 by default (top-left corner) while the other methods accept a single parameter, also 1 by default.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Set the cursor position to the second column of
	   the second row, print "Hello World!", then print
	   a new line. */
	std:: cout << csi::cursor_position(2, 2)
	           << "Hello World!"
	           << std::endl;
}
```
## How to erase the display:
The `erase_display` and `erase_line` methods accept `erase_mode` values as parameters and return strings which erase lines or even the whole display. `erase_mode` is an `enum class` which defines three modes: `to_end`, `to_beginning`, and `all`. `to_end` erases from the cursor to the end of the line/display. `to_beginning` erases from the cursor to the beginning of the line/display. `all` erases the entire line/display. For both methods, `erase_mode` is `all` by default.
```cpp
#include <iostream>
#include "csi.hpp"

int main(){
	/* Erase the display, set the cursor position to
	   the top-left, print "Hello World!", then print
	   a new line */
	std:: cout << csi::erase_display()
	           << csi::cursor_position()
	           << "Hello World!"
	           << std::endl;
}
```
